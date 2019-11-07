#pragma once
class StartingSolutionGenerator
{
public:
	StartingSolutionGenerator(int k);
	~StartingSolutionGenerator();
	Chromosome generateRandomSolution(std::vector<Item>* items);
private:
	int knapsackCapability;
};

