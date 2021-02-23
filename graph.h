#ifndef __COORDINATE__
#define __COORDINATE__
#include "MAIN.h"
#include "Point.h"
class Graph{
protected:
	static int unit, row, col;
public:
	Graph();
	static int getUnit();
	static int getRow();
	static int getCol();
	static void setRow();
	static void setCol();
	virtual void abstract()=0;
};
#endif