#include "riddles.h"
#include<iostream>
#include<string>
using namespace std;

riddles::riddles()
{
	setriddlesolved(1, false);
}

void riddles::riddle1()
{
	string riddleanswer;
	bool unsolve = true;
	while (unsolve == true)
	{
		cout << "You have found a mini fridge but it's locked. To unlock it, you need to solve this riddle:\n" << endl;
		cout << "What word becomes shorter when you add two letters? ";
		cin >> riddleanswer;
		int tries;
		tries = 3;
		if (riddleanswer == "short")
		{
			cout << "Correct!\n" << endl;
			dealriddledamage(0);
			cout << "You have found a key labeled 'warp key 1'." << endl;
			cout << "You have found a box of shortbread cookies" << endl;
			cout << "You have found a box of chocolate chip cookies" << endl;
			cout << "You have found a box of chinese almond cookies" << endl;
			unsolve = false;
		}
		while (riddleanswer != "short")
		{
			tries -= 1;
			cout << "\nI'm sorry that is incorrect. Your have " << tries << " tries left to answer correct." << endl;
			cout << "What word becomes shorter when you add two letters? ";
			cin >> riddleanswer;
			if (riddleanswer == "short")
			{
				cout << "Correct!\n" << endl;
				dealriddledamage(0);
				cout << "You have found a key labeled 'warp key 1'" << endl;
				cout << "You have found a box of shortbread cookies" << endl;
				cout << "You have found a box of chocolate chip cookies" << endl;
				cout << "You have found a box of chinese almond cookies" << endl;
				tries += 1;
				unsolve = false;
			}
			if (tries <= 0)
			{
				cout << "\nThe correct answer is 'short'. You have sacrificed 10% of health to open the fridge.\n" << endl;
				dealriddledamage(10);
				cout << "You have found a key labeled 'warp key 1'." << endl;
				cout << "You have found a box of shortbread cookies" << endl;
				cout << "You have found a box of chocolate chip cookies" << endl;
				cout << "You have found a box of chinese almond cookies" << endl;
				riddleanswer = "short";
				unsolve = false;
			}
		}
	}
}

//key label
void riddles::riddle2()
{
	string riddleanswer;
	bool unsolve = true;
	while (unsolve == true)
	{
		cout << "You have found a mini fridge but it's locked. To unlock it, you need to solve this riddle:\n" << endl;
		cout << "What gets wetter the more it dries? ";
		cin >> riddleanswer;
		int tries;
		tries = 3;
		if (riddleanswer == "towel")
		{
			cout << "Correct!\n" << endl;
			dealriddledamage(0);
			cout << "You have found a key labeled 'warp key 2'" << endl;
			unsolve = false;
		}
		while (riddleanswer != "towel")
		{
			tries -= 1;
			cout << "\nI'm sorry that is incorrect. Your have " << tries << " tries left to answer correct." << endl;
			cout << "What gets wetter the more it dries? ";
			cin >> riddleanswer;
			if (riddleanswer == "towel")
			{
				cout << "Correct!\n" << endl;
				dealriddledamage(0);
				cout << "You have found a key labeled 'warp key 2'" << endl;
				tries += 1;
				unsolve = false;
			}
			if (tries <= 0)
			{
				cout << "\nThe correct answer is 'towel'. You have sacrificed 10% of health to open the fridge.\n" << endl;
				dealriddledamage(10);
				cout << "You have found a key labeled 'warp key 2'." << endl;
				riddleanswer = "towel";
				unsolve = false;
			}
		}
	}
}

//monster chest
void riddles::riddle3()
{
	string riddleanswer;
	bool unsolve = true;
	while (unsolve == true)
	{
		cout << "You have found a mini fridge but it's locked. To unlock it, you need to solve this riddle:\n" << endl;
		cout << "The more of these you take, the more you leave. What is it? ";
		cin >> riddleanswer;
		int tries;
		tries = 3;
		if (riddleanswer == "footsteps")
		{
			cout << "Correct!\n" << endl;
			dealriddledamage(0);
			cout << "You have encounter a cookie troll!" << endl;
			unsolve = false;
		}
		while (riddleanswer != "footsteps")
		{
			tries -= 1;
			cout << "\nI'm sorry that is incorrect. Your have " << tries << " tries left to answer correct." << endl;
			cout << "The more of these you take, the more you leave. What is it? ";
			cin >> riddleanswer;
			if (riddleanswer == "footsteps")
			{
				cout << "Correct!\n" << endl;
				dealriddledamage(0);
				cout << "You have encounter a cookie troll!" << endl;
				tries += 1;
				unsolve = false;
			}
			if (tries <= 0)
			{
				cout << "\nThe correct answer is 'footsteps'. You have sacrificed 10% of health to open the fridge.\n" << endl;
				dealriddledamage(10);
				cout << "You have encounter a cookie troll!" << endl;
				riddleanswer = "footsteps";
				unsolve = false;
			}
		}
	}
}

//key chest
void riddles::riddle4()
{
	string riddleanswer;
	bool unsolve = true;
	while (unsolve == true)
	{
		cout << "You have found a mini fridge but it's locked. To unlock it, you need to solve this riddle:\n" << endl;
		cout << "What object do you go on red but stop on green? ";
		cin >> riddleanswer;
		int tries;
		tries = 3;
		if (riddleanswer == "watermelon")
		{
			cout << "Correct!\n" << endl;
			dealriddledamage(0);
			cout << "You have found a key labeled 'warp key 3'." << endl;
			unsolve = false;
		}
		while (riddleanswer != "watermelon")
		{
			tries -= 1;
			cout << "\nI'm sorry that is incorrect. Your have " << tries << " tries left to answer correct." << endl;
			cout << "What object do you go on red but stop on green? ";
			cin >> riddleanswer;
			if (riddleanswer == "watermelon")
			{
				cout << "Correct!\n" << endl;
				dealriddledamage(0);
				cout << "You have found a key labeled 'warp key 3'." << endl;
				tries += 1;
				unsolve = false;
			}
			if (tries <= 0)
			{
				cout << "\nThe correct answer is 'watermelon'. You have sacrificed 10% of health to open the fridge.\n" << endl;
				dealriddledamage(10);
				cout << "You have found a key labeled 'warp key 3'." << endl;
				riddleanswer = "watermelon";
				unsolve = false;
			}
		}
	}
}

//moster chest
void riddles::riddle5()
{
	string riddleanswer;
	bool unsolve = true;
	while (unsolve == true)
	{
		cout << "You have found a mini fridge but it's locked. To unlock it, you need to solve this riddle:\n" << endl;
		cout << "The maker doesn't want it. The buyer doesn't use it. The user can't see it. What is it? ";
		cin >> riddleanswer;
		int tries;
		tries = 3;
		if (riddleanswer == "coffin")
		{
			cout << "Correct!\n" << endl;
			dealriddledamage(0);
			cout << "You have encounter a cookie troll!" << endl;
			unsolve = false;
		}
		while (riddleanswer != "coffin")
		{
			tries -= 1;
			cout << "\nI'm sorry that is incorrect. Your have " << tries << " tries left to answer correct." << endl;
			cout << "The maker doesn't want it. The buyer doesn't use it. The user can't see it. What is it? ";
			cin >> riddleanswer;
			if (riddleanswer == "coffin")
			{
				cout << "Correct!\n" << endl;
				dealriddledamage(0);
				cout << "You have encounter a cookie troll!" << endl;
				tries += 1;
				unsolve = false;
			}
			if (tries <= 0)
			{
				cout << "\nThe correct answer is 'coffin'. You have sacrificed 10% of health to open the fridge.\n" << endl;
				dealriddledamage(10);
				cout << "You have encounter a cookie troll!" << endl;
				riddleanswer = "coffin";
				unsolve = false;
			}
		}
	}
}

void riddles::riddle6()
{
	string riddleanswer;
	bool unsolve = true;
	while (unsolve == true)
	{
		cout << "You have found a mini fridge but it's locked. To unlock it, you need to solve this riddle:\n" << endl;
		cout << "What is always coming, but never actually arrives? ";
		cin >> riddleanswer;
		int tries;
		tries = 3;
		if (riddleanswer == "tomorrow")
		{
			cout << "Correct!\n" << endl;
			dealriddledamage(0);
			cout << "You have encounter a cookie troll!" << endl;
			unsolve = false;
		}
		while (riddleanswer != "tomorrow")
		{
			tries -= 1;
			cout << "\nI'm sorry that is incorrect. Your have " << tries << " tries left to answer correct." << endl;
			cout << "What is always coming, but never actually arrives? ";
			cin >> riddleanswer;
			if (riddleanswer == "tomorrow")
			{
				cout << "Correct!\n" << endl;
				dealriddledamage(0);
				cout << "You have encounter a cookie troll!" << endl;
				tries += 1;
				unsolve = false;
			}
			if (tries <= 0)
			{
				cout << "\nThe correct answer is 'tomorrow'. You have sacrificed 10% of health to open the fridge.\n" << endl;
				dealriddledamage(10);
				cout << "You have encounter a cookie troll!" << endl;
				riddleanswer = "tomorrow";
				unsolve = false;
			}
		}
	}
}

void riddles::riddle7()
{
	string riddleanswer;
	bool unsolve = true;
	while (unsolve == true)
	{
		cout << "You have found a mini fridge but it's locked. To unlock it, you need to solve this riddle:\n" << endl;
		cout << "What comes once in a minute, twice in a moment, but never in a thousand years? ";
		cin >> riddleanswer;
		int tries;
		tries = 3;
		if (riddleanswer == "m")
		{
			cout << "Correct!\n" << endl;
			dealriddledamage(0);
			unsolve = false;
		}
		while (riddleanswer != "m")
		{
			tries -= 1;
			cout << "\nI'm sorry that is incorrect. Your have " << tries << " tries left to answer correct." << endl;
			cout << "What comes once in a minute, twice in a moment, but never in a thousand years? ";
			cin >> riddleanswer;
			if (riddleanswer == "m")
			{
				cout << "Correct!\n" << endl;
				dealriddledamage(0);
				tries += 1;
				unsolve = false;
			}
			if (tries <= 0)
			{
				cout << "\nThe correct answer is 'm'. You have sacrificed 10% of health to open the fridge.\n" << endl;
				dealriddledamage(10);
				riddleanswer = "m";
				unsolve = false;
			}
		}
	}
}

void riddles::setriddlesolved(int riddlenumber, bool ans)
{
	if (riddlenumber == 1)
	{
		riddle1solved = ans;
	}
	if (riddlenumber == 2)
	{
		riddle2solved = ans;
	}
	if (riddlenumber == 3)
	{
		riddle3solved = ans;
	}
	if (riddlenumber == 4)
	{
		riddle4solved = ans;
	}
	if (riddlenumber == 5)
	{
		riddle5solved = ans;
	}
	if (riddlenumber == 6)
	{
		riddle6solved = ans;
	}
	if (riddlenumber == 7)
	{
		riddle7solved = ans;
	}
}

bool riddles::getriddlesolved(int riddlenumber)
{
	bool solved;
	if (riddlenumber == 1)
	{
		solved = riddle1solved;
	}
	if (riddlenumber == 2)
	{
		solved = riddle2solved;
	}
	if (riddlenumber == 3)
	{
		solved = riddle3solved;
	}
	if (riddlenumber == 4)
	{
		solved = riddle4solved;
	}
	if (riddlenumber == 5)
	{
		solved = riddle5solved;
	}
	if (riddlenumber == 6)
	{
		solved = riddle6solved;
	}
	if (riddlenumber == 7)
	{
		solved = riddle7solved;
	}
	return solved;
}

void riddles::dealriddledamage(int damagepoints)
{
	riddledamage = damagepoints;
}

int riddles::returnriddledamage()
{
	return riddledamage;
}