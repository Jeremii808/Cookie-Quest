#ifndef ITEMS_H
#define ITEMS_H

class items
{
private:
	bool key1;
	bool key2;
	bool key3;
	bool cookiecats;

public:
	//Items class constructor
	items();

	//precondition: takes in key number to set and if true or false if the key is set
	//postcondition: key is set determined by the number and if true or false
	void setkey(int, bool);

	//precondition: takes in the key number to set
	//postcondition: key is set determined by the number
	bool getkey(int);

	//precondition: takes in true of false
	//postcondition: determines if the cookie cats are found or not
	void setcookiecats(bool);

	//precondition: determines if the cookie cats are found or not
	//postcondition: returns the found status of the cookie cats
	bool getcookiecats();
};
#endif // !ITEMS_H