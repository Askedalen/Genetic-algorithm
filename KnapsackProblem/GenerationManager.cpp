#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "Chromosome.h"
#include "Item.h"
#include "Printer.h"
#include "Sorter.h"
#include "StartingSolutionGenerator.h"
#include "GenerationManager.h"


GenerationManager::GenerationManager(std::vector<Item>* i, int ksc, int ps, double mc)
{
	items = i;
	knapsackCapability = ksc;
	populationSize = ps;
	mutationChance = mc;
}


GenerationManager::~GenerationManager()
{
}


void GenerationManager::createInitialPopulation()
{
	StartingSolutionGenerator ssg(knapsackCapability);
	for (int i = 0; i < populationSize; i++) {
		Chromosome c = ssg.generateRandomSolution(items);
		calcSolution(&c);
		population.push_back(c);
	}
}

void GenerationManager::reproduce()
{
	// Create random pairs
	std::vector<std::vector<int>> chromosomePairs = selectPairs();

	// Two Point Crossover
	for (std::vector<int>& pair : chromosomePairs) {
		int p1 = rand() % items->size();
		int p2 = rand() % items->size();
		if (p1 > p2) {
			int temp = p1;
			p1 = p2;
			p2 = temp;
		}

		// Get the solutions from population
		Chromosome child1 = population[pair[0]];
		Chromosome child2 = population[pair[1]];
		std::vector<bool>* child1Solution = child1.getSolution();
		std::vector<bool>* child2Solution = child2.getSolution();
		// Swap values within the random interval
		for (int i = p1; i <= p2; i++) {
			bool temp = child1Solution->at(i);
			(*child1Solution)[i] = child2Solution->at(i);
			(*child2Solution)[i] = temp;
		}

		// Mutations
		int r = rand() % 100;
		double rnd = (double)r / 100.0;
		if (rnd >= mutationChance) {
			mutate(child1Solution);
		}
		r = rand() % 100;
		rnd = (double)r / 100.0;
		if (rnd >= mutationChance) {
			mutate(child2Solution);
		}

		// Calculate value and weight to use in sorting
		calcSolution(&child1);
		calcSolution(&child2);

		// Push children into population
		population.push_back(child1);
		population.push_back(child2);
	}
}

void GenerationManager::mutate(std::vector<bool>* s)
{
	int rnd = rand() % s->size();
	if ((*s)[rnd]) {
		(*s)[rnd] = false;
	} else {
		(*s)[rnd] = true;
	}
}

void GenerationManager::naturalSelection()
{
	Sorter sorter(items, knapsackCapability);
	sorter.sortPopulation(population);

	population.erase(population.begin(), population.begin() + populationSize);
}

Chromosome GenerationManager::geneticOptimize()
{
	std::cout << "Genetic optimizing." << std::endl;
	std::ofstream file("geneticAnalyze.txt");
	signed long long startTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	int stagnation = 0;
	Chromosome bestSolution = population.at(0);
	for (int i = 0; i < 10000; i++) {
		reproduce();
		naturalSelection();

		Chromosome c = population.back();
		if (bestSolution.getValue() <= c.getValue()) {
			bestSolution = c;
			stagnation = 0;
		} else {
			stagnation++;
			if (stagnation >= 1000) {
				break;
			}
		}
		signed long long timestampMcrs = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		signed long timeSinceStartMicrs = timestampMcrs - startTime;
		file << timeSinceStartMicrs << " " << bestSolution.getValue() << " " << population.at(0).getValue() << std::endl;
	}
	return population.back();
}

std::vector<std::vector<int>> GenerationManager::selectPairs()
{
	std::vector<std::vector<int>> chromosomePairs;
	std::vector<int> remainingChromosomes;

	// Fill remainingChromosomes with numbers
	for (int i = 0; i < populationSize; i++) {
		remainingChromosomes.push_back(i);
	}

	// Make random pairs
	for (int i = 0; i < populationSize/2; i++) {
		std::vector<int> pair;

		int rnd0 = rand() % remainingChromosomes.size();
		pair.push_back(remainingChromosomes[rnd0]);
		// Removes the chosen chromosome from the list after it has been used.
		// This way it won't choose the same chromosome twice.
		remainingChromosomes.erase(remainingChromosomes.begin() + rnd0);

		int rnd1 = rand() % remainingChromosomes.size();
		pair.push_back(remainingChromosomes[rnd1]);
		remainingChromosomes.erase(remainingChromosomes.begin() + rnd1);

		chromosomePairs.push_back(pair);
	}


	return chromosomePairs;
}

void GenerationManager::calcSolution(Chromosome* c)
{
	std::vector<bool>* child1Solution = c->getSolution();
	int cValue = 0;
	int cWeight = 0;
	for (int i = 0; i < items->size(); i++) {
		// Gets item if either chromosome contains the item
		if (child1Solution->at(i)) {
			Item* item = &(Item)items->at(i);

			cValue += item->getValue();
			cWeight += item->getWeight();
		}
	}
	c->setValue(cValue);
	c->setWeight(cWeight);
	c->setKnapsackCapability(&knapsackCapability);
}

