// KnapsackProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

#include "Chromosome.h"
#include "Item.h"
#include "ItemGenerator.h"
#include "Sorter.h"
#include "Printer.h"
#include "GenerationManager.h"

std::vector<Item> items;
bool useDefaultValues = true;

int main()
{
	srand(time(NULL));

	int numerOfItems = 100;
	std::cout << "Number of items: ";
	std::cin >> numerOfItems;

	ItemGenerator generator;
	items = generator.createItems(numerOfItems);

	do {
		int knapsackCapability = numerOfItems * 2.5;
		int populationSize = 50;
		double mutationChance = 0.5;

		if (!useDefaultValues) {
			std::cout << "Max weight: ";
			std::cin >> knapsackCapability;
			std::cout << "Population size: ";
			std::cin >> populationSize;
			
		}
		std::cout << "Mutation chance: ";
		std::cin >> mutationChance;
		
		GenerationManager gm(&items, knapsackCapability, populationSize, mutationChance);
		gm.createInitialPopulation();
		Chromosome bestSolution = gm.geneticOptimize();
		std::cout << "Best solution:" << std::endl;
		Printer::printChromosome(bestSolution);

		char cont;
		std::cout << "Create new solution? (y/n)" << std::endl;
		std::cin >> cont;
		if (cont != 'y') {
			break;
		}
	} while (true);
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
