#include "items.h"

items::items()
{
	setkey(1, false);
}

void items::setkey(int keynum, bool recieved)
{
	if (keynum == 1)
	{
		key1 = recieved;
	}
	if (keynum == 2)
	{
		key2 = recieved;
	}
	if (keynum == 3)
	{
		key3 = recieved;
	}
}

bool items::getkey(int keynum)
{
	bool key;
	if (keynum == 1)
	{
		key = key1;
	}
	if (keynum == 2)
	{
		key = key2;
	}
	if (keynum == 3)
	{
		key = key3;
	}
	return key;
}

void items::setcookiecats(bool found)
{
	cookiecats = found;
}

bool items::getcookiecats()
{
	return cookiecats;
}