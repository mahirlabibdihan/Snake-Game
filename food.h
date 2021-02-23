#ifndef __FOOD__
#define __FOOD__
#include "Graph.h"
#include "Circle.h"
#include "Animal.h"
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