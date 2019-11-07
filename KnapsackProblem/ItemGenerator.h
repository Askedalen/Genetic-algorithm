#pragma once
class ItemGenerator
{
public:
	ItemGenerator();
	~ItemGenerator();
	std::vector<Item> createItems(int itemCount);
private:
	std::vector<Item> items;
};

