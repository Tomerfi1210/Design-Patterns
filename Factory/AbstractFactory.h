#include <iostream>
#include <memory>
#include <map>
#include "HotDrink.h"
#include "DrinkFactory.h"
using namespace std;

//Not good.
unique_ptr<HotDrink> make_drink(string type)
{
    unique_ptr<HotDrink> drink;
    if (type == "tea")
    {
        drink = make_unique<Tea>();
        drink->prepare(200);
    }
    else
    {
        drink = make_unique<Coffee>();
        drink->prepare(50);
    }
    return drink;
}

int main()
{
    auto d = make_drink("tea");

    DrinkFactory df;
    auto drink = df.make_drink("coffee");
  

    DrinkWithVolumeFactory dv;
    auto coffee = dv.make_drink("coffee");
    coffee->prepare(500);

    getchar();
    return 0;
}