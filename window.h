#ifndef __GAME_WINDOW__
#define __GAME_WINDOW__
#include "main.h"
#include "color.h"
#include "graph.h"
#include "box.h"
class GameWindow {
public:
	Rectangle border;
	void draw();
};
#endif