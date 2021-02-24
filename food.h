#ifndef __FOOD__
#define __FOOD__
#include "Grid.h"
#include "Circle.h"
#include "Snake.h"
#include "MAIN.h"
class Food: public Circle {
private:
public:
	int timer;
	Food();
	bool isEaten();
	void newLocation();
	void draw();
};
#endif