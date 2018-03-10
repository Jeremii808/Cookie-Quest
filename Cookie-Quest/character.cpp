#include "character.h"
#include<iostream>
using namespace std;

character::character()
{

}

void character::addtoinventory(string item)
{
	inventory.push_back(item);
}

void character::checkinventory()
{
	if (inventory.empty())
	{
		cout << "You have nothing in your inventory" << endl;
	}
	for (unsigned i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}
}

void character::deleteitem(string item)
{
	auto it = find(inventory.begin(), inventory.end(), item);
	if (it != inventory.end())
	{
		inventory.erase(it);
	}
}

void character::sethealth(int hp)
{
	health = hp;
}

int character::gethealth()
{
	return health;
}

void character::healthdamage(int damage)
{
	health = health - damage;
}
