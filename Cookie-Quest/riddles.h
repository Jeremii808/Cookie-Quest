#ifndef RIDDLES_H
#define RIDDLES_H

class riddles
{
protected:
	bool riddle1solved;
	bool riddle2solved;
	bool riddle3solved;
	bool riddle4solved;
	bool riddle5solved;
	bool riddle6solved;
	bool riddle7solved;
	int riddledamage;
public:
	//riddle class constructor
	riddles();

	//precondition: prints out a unique riddle for the player to solve
	//postcondition: riddle is solved by player or solved on its own
	void riddle1();

	//precondition: prints out a unique riddle for the player to solve
	//postcondition: riddle is solved by player or solved on its own
	void riddle2();

	//precondition: prints out a unique riddle for the player to solve
	//postcondition: riddle is solved by player or solved on its own
	void riddle3();

	//precondition: prints out a unique riddle for the player to solve
	//postcondition: riddle is solved by player or solved on its own
	void riddle4();

	//precondition: prints out a unique riddle for the player to solve
	//postcondition: riddle is solved by player or solved on its own
	void riddle5();

	//precondition: prints out a unique riddle for the player to solve
	//postcondition: riddle is solved by player or solved on its own
	void riddle6();

	//precondition: prints out a unique riddle for the player to solve
	//postcondition: riddle is solved by player or solved on its own
	void riddle7();

	//precondition: takes in an integer that determines which riddle number and if to solve it or not
	//postcondition: sets a riddle to be solved or unsolved
	void setriddlesolved(int, bool);

	//precondition: takes in an integer that represents a riddle number
	//postcondition: returns the status of a riddle if its solved or not
	bool getriddlesolved(int);

	//precondition: takes in a how much damage to deal to player when answering a riddle
	//postcondition: damage is used to subtract from player health level
	void dealriddledamage(int);

	//precondition: determines how much damage was done to player
	//postcondition: return damage that is delt
	int returnriddledamage();
};
#endif // !RIDDLES_H