#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class gameworld
{
protected:
	char world[4][4][4];
	char playerposition;

public:
	//constructor
	//intiates the 3D array and create the game world
	gameworld();

	//precondition: the player's location is set and marked by an 'X'
	//				all rooms that the player is not in is marked by an 'O'
	//postcondition: prints out a map that shows the player location
	void printmap();

	//precondition: the player has not been added to the world
	//postcondition: the player is added to the world in a specific location
	//				 determined by the function parameters
	bool setplayerposition(int, int, int);

	//precondition: determines what floor the player is on
	//postcondition: returns the floor number the player is on
	int getplayerfloorposition();

	//preconditon: the player's current location is determined
	//postcondition: player's location is incremented to move right
	void goright();

	//preconditon: the player's current location is determined
	//postcondition: player's location is decremented to move left
	void goleft();

	//preconditon: the player's current location is determined
	//postcondition: player's location is decremented to move forward
	void goforward();

	//preconditon: the player's current location is determined
	//postcondition: player's location is incremented to move backward
	void gobackward();

	//precondition: the player has not enountered a warp room
	//postcondition: the player moves up one floor
	void warp();

	//displays a list of commands for the player to use in the game
	void helpscreen();

	//prints out an introduction of the game
	void intro();

	//precondition: trapholes are not set in the world
	//postconition:certain spots in the worlds become trapholes.
	//             the trapholes are marked 'T' after encountered to let players know where they are
	void traphole();

	//precondition: Mini fridges are not created in the game yet
	//postcondition: mini fridges are placed in the game. Some fridges have keys, some have trolls, and
	//				 some have boxes of cookies. Each fridge can only be open when the player solves a riddle.
	void setboxes();

	//precondition: looks through a vector for anything in it
	//postcondition: prints out a list of what is in the inventory vector
	void printinventory();

	void printhealthgauge();
};
#endif // !GAMEWORLD_H

