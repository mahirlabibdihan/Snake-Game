#ifndef __WINDOW__
#define __WINDOW__
#include "main.h"
#include "color.h"
#include "graph.h"
#include "box.h"
class GameWindow {
public:
	Box border;
	void draw();
};
#endif