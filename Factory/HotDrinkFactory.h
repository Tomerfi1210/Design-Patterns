#pragma once
#include "HotDrink.h"

//interface
struct HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const = 0;
};