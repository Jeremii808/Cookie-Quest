#include "gameworld.h"
#include "character.h"
#include "riddles.h"
#include "items.h"
#include "monster.h"
#include<iostream>
using namespace std;

character player;
riddles riddle;
items item;
monster trolls;

gameworld::gameworld()
{
	//world[floor][updown][leftright]
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				world[i][j][k] = '-';
			}
		}
	}
	player.sethealth(100);
}

void gameworld::printmap()
{
	cout << "\nYour location is marked 'X' " << endl;
	cout << "Unlocked warp pads are marked 'W' " << endl;
	cout << "Discovered trap holes are marked 'T'\n" << endl;
	if (getplayerfloorposition() == 0)
	{
		cout << "1st Floor Map:" << endl;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cout << world[getplayerfloorposition()][j][k] << " ";
			}
			cout << endl;
		}
	}
	if (getplayerfloorposition() == 1)
	{
		cout << "2nd Floor Map:" << endl;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cout << world[getplayerfloorposition()][j][k] << " ";
			}
			cout << endl;
		}
	}
	if (getplayerfloorposition() == 2)
	{
		cout << "3rd Floor Map:" << endl;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cout << world[getplayerfloorposition()][j][k] << " ";
			}
			cout << endl;
		}
	}
	if (getplayerfloorposition() == 3)
	{
		cout << "Top Floor Map:" << endl;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cout << world[getplayerfloorposition()][j][k] << " ";
			}
			cout << endl;
		}
	}
}

bool gameworld::setplayerposition(int f, int ud, int lr)
{
	bool validdata = true;
	if ((f <= 3) && (ud <= 3) && (lr <= 3) && (f >= 0) && (ud >= 0) && (lr >= 0))
	{
		playerposition = 'X';
		world[f][ud][lr] = playerposition;
	}
	else
	{
		validdata = false;
	}
	return validdata;
}

int gameworld::getplayerfloorposition()
{
	int floor;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (world[i][j][k] == 'X')
				{
					floor = i;
				}
			}
		}
	}
	return floor;
}

void gameworld::goright()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (world[i][j][k] == 'X')
				{
					world[i][j][k] = '-';
					k += 1;
					setplayerposition(i, j, k);
					//printhealthgauge();
					while (k > 3)
					{
						cout << "You can't go right anymore" << endl;
						k = 3;
						setplayerposition(i, j, k);
					}
				}
			}
		}
	}
	warp();
	traphole();
	setboxes();
}

void gameworld::goleft()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (world[i][j][k] == 'X')
				{
					world[i][j][k] = '-';
					k -= 1;
					setplayerposition(i, j, k);
					//printhealthgauge();
					while (k < 0)
					{
						cout << "You can't go left anymore" << endl;
						k = 0;
						setplayerposition(i, j, k);
					}
				}
			}
		}
	}
	warp();
	traphole();
	setboxes();
}

void gameworld::goforward()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (world[i][j][k] == 'X')
				{
					world[i][j][k] = '-';
					j -= 1;
					setplayerposition(i, j, k);
					//printhealthgauge();
					while (j < 0)
					{
						cout << "You can't go forward anymore" << endl;
						j = 0;
						setplayerposition(i, j, k);
					}
				}
			}
		}
	}
	warp();
	traphole();
	setboxes();
}

void gameworld::gobackward()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (world[i][j][k] == 'X')
				{
					world[i][j][k] = '-';
					j += 1;
					setplayerposition(i, j, k);
					//printhealthgauge();
					while (j > 3)
					{
						cout << "You can't go backward anymore" << endl;
						j = 3;
						setplayerposition(i, j, k);
					}
				}
			}
		}
	}
	warp();
	traphole();
	setboxes();
}

void gameworld::warp()
{
	if (world[0][0][3] == 'X')
	{
		if (item.getkey(1) == true)
		{
			world[0][0][3] = 'W';
			world[1][0][3] = 'X';
			cout << "You used warp key 1 to warp to the second floor" << endl;
		}
		else
		{
			cout << "You have found a warp pad but it's locked. Try and find a key. " << endl;
		}
	}
	if (world[1][2][1] == 'X')
	{
		if (item.getkey(2) == true)
		{
			world[1][2][1] = 'W';
			world[2][2][1] = 'X';
			cout << "You used warp key 2 to warp to the third floor" << endl;
		}
		else
		{
			cout << "You have found a warp pad but it's locked. Try and find a key." << endl;
		}

	}
	if (world[2][3][3] == 'X')
	{
		if (item.getkey(3) == true)
		{
			world[2][3][3] = 'W';
			world[3][3][3] = 'X';
			cout << "You used warp key 3 to warp to the top floor." << endl;
			cout << "Somewhere on this floor is a mini fridge that contains the box of the last cookie cats" << endl;
		}
		else
		{
			cout << "You have found a warp pad but it's locked. Try and find a key." << endl;
		}
	}
}

void gameworld::helpscreen()
{
	cout << " ----------------------------------- " << endl;
	cout << "|         List of commands          |" << endl;
	cout << " ----------------------------------- " << endl;
	cout << "           forward -> w\n            " << endl;
	cout << "left -> a                right -> d\n" << endl;
	cout << "           backward -> s\n           " << endl;
	cout << "       check inventory -> i          " << endl;
	cout << "        quit the game -> q\n         " << endl;
	printhealthgauge();
}

void gameworld::intro()
{
	cout << " -------------------------------------------------------------------------------------- " << endl;
	cout << "|                                        COOKIE CAT QUEST                              |" << endl;
	cout << " --------------------------------------------------------------------------------------\n" << endl;
	cout << "Let's begin....                                                 ^               ^       " << endl;
	cout << "You will be playing as Steven Universe.                        ^ ^             ^ ^      " << endl;
	cout << "You have just entered the first floor of a 4-story tower.     ^   ^^^^^^^^^^^^^   ^     " << endl;
	cout << "Rumor has it, there is a mini fridge on the top floor        ^                     ^    " << endl;
	cout << "that contains a box of the last 10 cookie cats in           ^     ( )       ( )     ^   " << endl;
	cout << "the world. Make your way through the tower and             ^                         ^  " << endl;
	cout << "reach the top floor to find the box of the last             ^                       ^   " << endl;
	cout << "cookiecats. Watch out for trapholes and cookie trolls        ^                     ^    " << endl;
	cout << "along the way. To move to up a floor, you need to             ^                   ^     " << endl;
	cout << "find and unlock the warp pads. Good Luck!                       ^^^^^^^^^^^^^^^^^       " << endl;
	helpscreen();
}

void gameworld::traphole()
{
	if (world[1][1][3] == 'X')
	{
		world[1][1][3] = 'T';//revert to - if fail
		world[0][1][3] = 'X';
		cout << "You encountered a traphole and fell down to the first floor" << endl;
	}
	if (world[2][0][2] == 'X')
	{
		world[2][0][2] = 'T';
		world[1][0][2] = 'X';
		cout << "You encountered a traphole and fell down to the second floor" << endl;
	}
	if (world[3][3][2] == 'X')
	{
		world[3][3][2] = 'T';
		world[2][3][2] = 'X';
		cout << "You encountered a traphole and fell down to the third floor" << endl;
	}
}

void gameworld::setboxes()
{
	//fridge1 with warp key 1 and cookie boxes
	if (world[0][2][3] == 'X')
	{
		if (riddle.getriddlesolved(1) == false)
		{
			riddle.riddle1();
			player.healthdamage(riddle.returnriddledamage());
			riddle.setriddlesolved(1, true);
			item.setkey(1, true);
			if (item.getkey(1) == true)
			{
				player.addtoinventory("warp key 1");
				player.addtoinventory("box of shortbread cookies");
				player.addtoinventory("box of chocolate chip cookies");
				player.addtoinventory("box of chinese almond cookies");
			}
		}
		else
		{
			cout << "A mini fridge was opened here." << endl;
		}
	}

	//fridge2 with warp key 2
	if (world[1][3][0] == 'X')
	{
		if (riddle.getriddlesolved(2) == false)
		{
			riddle.riddle2();
			player.healthdamage(riddle.returnriddledamage());
			riddle.setriddlesolved(2, true);
			item.setkey(2, true);
			if (item.getkey(2) == true)
			{
				player.addtoinventory("warp key 2");
			}
		}
		else
		{
			cout << "A mini fridge was opened here." << endl;
		}
	}

	//fridge3 with cookie troll 1
	if (world[1][0][1] == 'X')
	{
		if (riddle.getriddlesolved(3) == false)
		{
			riddle.riddle3();
			player.healthdamage(riddle.returnriddledamage());
			riddle.setriddlesolved(3, true);
			trolls.setmonster(1, true);
			char feedtrollans;
			do
			{
				cout << "The troll looks hungry... Would you like to feed it? (y/n) ";
				cin >> feedtrollans;
				switch (feedtrollans)
				{
				case 'y':
					trolls.feedmonster(1);
					player.deleteitem("box of shortbread cookies");
					cout << "\nYou have fed the troll your box of shortbread cookies." << endl;
					cout << "The troll is happy and leaves the treasure chest" << endl;
					break;
				case 'n':
					cout << "\nThe troll got angry and attacked you. You lost 10% of health" << endl;
					player.healthdamage(10);
					trolls.feedmonster(1);//it secretly needs to be fed to end the loop
					break;
				default:
					cout << "I'm sorry your answer was not valid" << endl;
					break;
				}
			} while (trolls.checkiffed(1) == false);
		}
		else
		{
			cout << "A mini fridge was opened here." << endl;
		}
	}

	//fridge with warp key 3
	if (world[2][0][3] == 'X')
	{
		if (riddle.getriddlesolved(4) == false)
		{
			riddle.riddle4();
			player.healthdamage(riddle.returnriddledamage());
			riddle.setriddlesolved(4, true);
			item.setkey(3, true);
			if (item.getkey(3) == true)
			{
				player.addtoinventory("warp key 3");
			}
		}
		else
		{
			cout << "A mini fridge was opened here." << endl;
		}
	}

	//fridge with troll 2
	if (world[2][1][1] == 'X')
	{
		if (riddle.getriddlesolved(5) == false)
		{
			riddle.riddle5();
			player.healthdamage(riddle.returnriddledamage());
			riddle.setriddlesolved(5, true);
			trolls.setmonster(2, true);
			char feedtrollans;
			do
			{
				cout << "The troll looks hungry... Would you like to feed it? (y/n) ";
				cin >> feedtrollans;
				switch (feedtrollans)
				{
				case 'y':
					trolls.feedmonster(2);
					player.deleteitem("box of chocolate chip cookies");
					cout << "\nYou have fed the troll your box of chocolate chip cookies." << endl;
					cout << "The troll is happy and leaves the treasure chest" << endl;
					break;
				case 'n':
					cout << "\nThe troll got angry and attacked you. You lost 10% of health" << endl;
					player.healthdamage(10);
					trolls.feedmonster(2);//it secretly needs to be fed to end the loop
					break;
				default:
					cout << "I'm sorry your answer was not valid" << endl;
					break;
				}
			} while (trolls.checkiffed(2) == false);
		}
		else
		{
			cout << "A mini fridge was opened here." << endl;
		}
	}

	//fridge with troll
	if (world[3][1][2] == 'X')
	{
		if (riddle.getriddlesolved(6) == false)
		{
			riddle.riddle6();
			player.healthdamage(riddle.returnriddledamage());
			riddle.setriddlesolved(6, true);
			trolls.setmonster(3, true);
			char feedtrollans;
			do
			{
				cout << "The troll looks hungry... Would you like to feed it? (y/n) ";
				cin >> feedtrollans;
				switch (feedtrollans)
				{
				case 'y':
					trolls.feedmonster(3);
					player.deleteitem("box of chinese almond cookies");
					cout << "\nYou have fed the troll your box of box of chinese almond cookies." << endl;
					cout << "The troll is happy and leaves the treasure chest" << endl;
					break;
				case 'n':
					cout << "\nThe troll got angry and attacked you. You lost 10% of health" << endl;
					player.healthdamage(10);
					trolls.feedmonster(3);//it secretly needs to be fed to end the loop
					break;
				default:
					cout << "I'm sorry your answer was not valid" << endl;
					break;
				}
			} while (trolls.checkiffed(3) == false);
		}
		else
		{
			cout << "A mini fridge was opened here." << endl;
		}
	}

	//cookie cat fridge
	if (world[3][1][1] == 'X')
	{
		if (riddle.getriddlesolved(7) == false)
		{
			riddle.riddle7();
			player.healthdamage(riddle.returnriddledamage());
			riddle.setriddlesolved(7, true);
			item.setcookiecats(true);
			if (item.getcookiecats() == true)
			{
				player.addtoinventory("box of the last cookie cats");
				cout << "\nCongratulations!\n" << endl;
				cout << "You have found the box of the last cookie cats.\n" << endl;
				cout << "Thanks for playing!\n" << endl;
				system("pause");
				exit(0);
			}
		}
	}
}

void gameworld::printinventory()
{
	cout << "Inventory:" << endl;
	player.checkinventory();
}

void gameworld::printhealthgauge()
{
	cout << "-------------------" << endl;
	cout << "Health Level: " << player.gethealth() << "%" << endl;
	cout << "-------------------\n" << endl;
}