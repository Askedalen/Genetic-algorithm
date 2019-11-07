#include "pch.h"
#include <iostream>
#include <vector>
#include "Chromosome.h"
#include "Item.h"

#include "Printer.h"


Printer::Printer()
{
}


Printer::~Printer()
{
}

void Printer::printPopulation(std::vector<Chromosome>& population)
{
	for (Chromosome& c : population) {
		printChromosome(c);
	}
	std::cout << std::endl;
}

void Printer::printItems(std::vector<Item>& items)
{
	for (Item& i : items) {
		std::cout << i.getValue() << " " << i.getWeight() << " | ";
	}
	std::cout << std::endl;
}

void Printer::printChromosome(Chromosome& chromosome)
{
	std::vector<bool>* solution = chromosome.getSolution();
	for (const bool& b : *solution) {
		std::cout << (b) ? '1' : '0';
	}
	std::cout << " " << chromosome.getWeight() << " " << chromosome.getValue() << std::endl;
}
