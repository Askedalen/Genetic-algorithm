#include "pch.h"
#include <vector>
#include "Item.h"

#include "ItemGenerator.h"


ItemGenerator::ItemGenerator()
{
}


ItemGenerator::~ItemGenerator()
{
}

std::vector<Item> ItemGenerator::createItems(int itemCount)
{
	for (int i = 0; i < itemCount; i++) {
		items.push_back(Item());
	}
	return items;
}
