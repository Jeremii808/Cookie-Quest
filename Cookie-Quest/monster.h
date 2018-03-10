#ifndef MONSTER_H
#define MONSTER_H

class monster
{
private:
	bool monster1;
	bool monster2;
	bool monster3;
	bool monsterpresent;
	bool monster1fed;
	bool monster2fed;
	bool monster3fed;
public:
	monster();
	void setmonster(int, bool);
	void feedmonster(int);
	bool checkiffed(int);

};
#endif // !MONSTER_H