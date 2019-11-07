#include "pch.h"
#include <vector>

#include "Chromosome.h"


Chromosome::Chromosome(std::vector<bool> s, int* ksc)
{
	solution = s;
	knapsackCapability = ksc;
}

Chromosome::Chromosome()
{
}


Chromosome::~Chromosome()
{
}

int Chromosome::getWeight()
{
	return weight;
}

void Chromosome::setWeight(int w)
{
	weight = w;
}

int Chromosome::getValue()
{
	return value;
}

void Chromosome::setValue(int v)
{
	value = v;
}

int* Chromosome::getKnapsackCapability()
{
	return knapsackCapability;
}

void Chromosome::setKnapsackCapability(int* k)
{
	knapsackCapability = k;
}

std::vector<bool>* Chromosome::getSolution()
{
	return &solution;
}
