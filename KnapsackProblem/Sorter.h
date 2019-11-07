#pragma once
class Sorter
{
public:
	Sorter(std::vector<Item>* i, int ksc);
	~Sorter();
	std::vector<Item> sortItems(int sortType);
	void sortPopulation(std::vector<Chromosome>& population);
private:
	std::vector<Item> items;
	int knapsackCapability;
	static bool sortWeight(Item i1, Item i2);
	static bool sortWeightDesc(Item i1, Item i2);
	static bool sortValue(Item i1, Item i2);
	static bool sortValueDesc(Item i1, Item i2);
	static bool sortChromosomeValue(Chromosome i1, Chromosome i2);
};

