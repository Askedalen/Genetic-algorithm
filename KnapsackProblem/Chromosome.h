#pragma once
class Chromosome
{
public:
	Chromosome(std::vector<bool> s, int* ksc);
	Chromosome();
	~Chromosome();
	int getWeight();
	void setWeight(int w);
	int getValue();
	void setValue(int v);
	int* getKnapsackCapability();
	void setKnapsackCapability(int* k);
	std::vector<bool>* getSolution();
private:
	std::vector<bool> solution;
	int weight;
	int value;
	int* knapsackCapability;
};

