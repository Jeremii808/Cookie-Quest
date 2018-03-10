#include "monster.h"

monster::monster()
{
}

void monster::setmonster(int monsternum, bool inbox)
{
	if (monsternum == 1)
	{
		monster1 = inbox;
	}
	if (monsternum == 2)
	{
		monster2 = inbox;
	}
	if (monsternum == 3)
	{
		monster3 = inbox;
	}
}

void monster::feedmonster(int monsternum)
{
	if (monsternum == 1)
	{
		monster1fed = true;
	}
	if (monsternum == 2)
	{
		monster2fed = true;
	}
	if (monsternum == 3)
	{
		monster3fed = true;
	}
}

bool monster::checkiffed(int monsternum)
{
	bool fed;
	if (monsternum == 1)
	{
		fed = monster1fed;
	}
	if (monsternum == 2)
	{
		fed = monster2fed;
	}
	if (monsternum == 3)
	{
		fed = monster3fed;
	}
	return fed;
}