#pragma once
class GenerationManager
{
public:
	GenerationManager(std::vector<Item>* i, int ksc, int ps, double mc);
	~GenerationManager();
	void createInitialPopulation();
	Chromosome geneticOptimize();
private:
	double mutationChance;
	int knapsackCapability;
	int populationSize;
	void reproduce();
	void mutate(std::vector<bool>* s);
	void naturalSelection();
	std::vector<Item>* items;
	std::vector<Chromosome> population;
	std::vector<std::vector<int>> selectPairs();
	void calcSolution(Chromosome* c);
};

