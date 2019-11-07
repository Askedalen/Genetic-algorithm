#include "pch.h"

#include <vector>

#include "Chromosome.h"
#include "Item.h"
#include "StartingSolutionGenerator.h"


StartingSolutionGenerator::StartingSolutionGenerator(int k)
{
	knapsackCapability = k;
}


StartingSolutionGenerator::~StartingSolutionGenerator()
{
}

Chromosome StartingSolutionGenerator::generateRandomSolution(std::vector<Item>* items)
{
	std::vector<bool> solution(items->size());
	/* 
	remainingItems is a list of the indexes of all items remaining. 
	This is used to choose which item should be put in the knapsack,
	rather than selecting a random item from the items vector.
	*/
	std::vector<int> remainingItems;
	int knapSackWeight = 0;
	int rnd;

	// Add indexes for each item into remainingItems.
	for (int i = 0; i < items->size(); i++) {
		remainingItems.push_back(i);
	}

	do {
		// Exit loop if there are no remaining items.
		if (remainingItems.size() <= 0) {
			break;
		}
		// Pick random item index not already true in solution
		rnd = rand() % remainingItems.size();
		Item* rndItem = &(Item)items->at(remainingItems[rnd]);
		// If adding the item does not overfill the knapsack
		if (knapSackWeight + rndItem->getWeight() <= knapsackCapability) {
			// Add item index to solution
			solution[remainingItems[rnd]] = true;
			knapSackWeight += rndItem->getWeight();
		}
		// Remove the item from remainingItems
		remainingItems.erase(remainingItems.begin() + rnd);
	} while (true);
	Chromosome c(solution, &knapsackCapability);
	return c;
}
