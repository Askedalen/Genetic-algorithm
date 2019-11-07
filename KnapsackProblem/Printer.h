#pragma once
class Printer
{
public:
	Printer();
	~Printer();
	static void printPopulation(std::vector<Chromosome>& population);
	static void printItems(std::vector<Item>& items);
	static void printChromosome(Chromosome& chromosome);
};

