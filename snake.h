#ifndef __ANIMAL__
#define __ANIMAL__
#include "Circle.h"
#include "Main.h"
#include "Button.h"
#include "game_details.h"
#include "Food.h"
class Snake {
private:
	int length, dir;
	bool pause;
public:
	string name;
	vector<Circle> tail;
	Circle head;
	Snake();
	int getDir();
	int setDir(Direction A);
	int Length();
	void setName(string name);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void stop();
	void move();
	bool isStopped();
	void boundaryCheck();
	void insert();
	void extend();
	void draw();
	void reset();
	void save(ofstream& out);
	void load(ifstream& in);
};
#endif