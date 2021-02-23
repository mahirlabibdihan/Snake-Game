#ifndef __DETAILS__
#define __DETAILS__
#include "MAIN.h"
#include "Food.h"
#include "Animal.h"
class Details {
private:
	bool gameOver;
	int score, increment;
public:
	Details();
	int getScore();
	void incrementScore();
	bool isOver();
	void save();
	void load();
	void Over();
	void reset();
};
#endif