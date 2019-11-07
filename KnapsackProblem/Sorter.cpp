#include "pch.h"
#include <vector>
#include "Item.h"
#include <algorithm>

#include "Chromosome.h"
#include "Sorter.h"


Sorter::Sorter(std::vector<Item>* i, int ksc)
{
	Sorter::items = *i;
	Sorter::knapsackCapability = ksc;
}


Sorter::~Sorter()
{
}

bool Sorter::sortWeight(Item i1, Item i2) {
	return (i1.getWeight() < i2.getWeight());
}

bool Sorter::sortWeightDesc(Item i1, Item i2)
{
	return (i1.getWeight() > i2.getWeight());
}

bool Sorter::sortValue(Item i1, Item i2)
{
	return (i1.getValue() < i2.getValue());
}

bool Sorter::sortValueDesc(Item i1, Item i2)
{
	return (i1.getValue() > i2.getValue());
}

bool Sorter::sortChromosomeValue(Chromosome i1, Chromosome i2)
{
	// Initialize weight and value for both chromosomes
	int chromosome1Value = 0;
	int chromosome2Value = 0;
	
	// If weight is less than or equal to capability, sets value. 
	// Otherwise sets value -1.
	if (i1.getWeight() <= *(i1.getKnapsackCapability())) {
		chromosome1Value = i1.getValue();
	} else {
		chromosome1Value = -1;
	}

	if (i2.getWeight() <= *(i2.getKnapsackCapability())) {
		chromosome2Value = i2.getValue();
	} else {
		chromosome2Value = -1;
	}

	// Returns true if value of chromosome 1 is less than that of chromosome 2.
	return (chromosome1Value < chromosome2Value);
}

std::vector<Item> Sorter::sortItems(int sortType)
{
	switch (sortType)
	{
	case 1:
		std::sort(items.begin(), items.end(), sortWeight);
		break;
	case 2:
		std::sort(items.begin(), items.end(), sortWeightDesc);
		break;
	case 3:
		std::sort(items.begin(), items.end(), sortValue);
		break;
	case 4:
		std::sort(items.begin(), items.end(), sortValueDesc);
		break;
	default:
		std::sort(items.begin(), items.end(), sortValueDesc);
		break;
	}
	return items;
}

void Sorter::sortPopulation(std::vector<Chromosome>& population)
{
	// Sorts the population based on the sortChromosomeValue function
	std::sort(population.begin(), population.end(), sortChromosomeValue);
}
