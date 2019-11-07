#include "pch.h"
#include <iostream>

#include "Item.h"

Item::Item()
{
	value = (rand() % 99) + 1;
	weight = (rand() % 10) + 1;
}

Item::~Item()
{
}

int Item::getValue() {
	return value;
}

int Item::getWeight() {
	return weight;
}
