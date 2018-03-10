#include<iostream>
#include<string>
#include "gameworld.h"
using namespace std;

int main()
{
	//gameworld class intialized
	gameworld world;

	//print out game info and intro
	world.intro();
	//set the player in the game
	world.setplayerposition(0, 3, 0);
	world.printmap();
	char input;
	do
	{
		cout << "\nPlease enter a command: ";
		cin >> input;
		switch (input)
		{
		case 'd':
			system("cls");
			world.intro();
			world.goright();
			world.printmap();
			break;
		case 'a':
			system("cls");
			world.intro();
			world.goleft();
			world.printmap();
			break;
		case 'w':
			system("cls");
			world.intro();
			world.goforward();
			world.printmap();
			break;
		case 's':
			system("cls");
			world.intro();
			world.gobackward();
			world.printmap();
			break;
		case 'i':
			system("cls");
			world.intro();
			world.printinventory();
			world.printmap();
			break;
		case 'q':
			system("cls");
			world.intro();
			cout << "\nThanks for playing!\n" << endl;
			break;
		default:
			system("cls");
			world.intro();
			world.printmap();
			cout << "\nI'm sorry, your command wasn't vaild." << endl;
			break;
		}
	} while (input != 'q');

	system("pause");
	return 0;
}