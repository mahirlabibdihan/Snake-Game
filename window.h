#ifndef __WINDOW__
#define __WINDOW__
#include "Main.h"
#include "Colors.h"
#include "Graph.h"
#include "Box.h"
class Window {
public:
	RGBColor graph;
	Box border;
	void draw();
};
#endif