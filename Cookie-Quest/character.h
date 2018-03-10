#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
#include<vector>
using namespace std;

class character
{
private:
	string name;
	int health;
	vector<string> inventory;

public:
	//character class constructor
	character();

	//precondition: takes in a string of the item to add to inventory
	//postcondition: adds the string item to the inventory string vector
	void addtoinventory(string);

	//precondition: check for anything in the inventory
	//postcondition: prints out whatever is in the inventory
	void checkinventory();

	//precondition: takes in a string of the item wanted to be deleted from the inventory
	//postcondition: deletes the string item wanted to be deleted
	void deleteitem(string);

	//precondition: takes in a parameter integer for the starting health level for the player
	//postcondition: sets the health level for the player
	void sethealth(int);

	//precondition: health level has been set
	//postcondition: returns current health level
	int gethealth();

	//precondition: takes a integer parameter that determines how much health level to subtract from current health level
	//postcondition: subtracts the parameter from the current health level
	void healthdamage(int);


};
#endif // !CHARACTER_H

