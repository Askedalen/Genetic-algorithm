#pragma once
class Item
{
public:
	Item();
	~Item();

	int getValue();
	int getWeight();
private:
	int value;
	int weight;
};

