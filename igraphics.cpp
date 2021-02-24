#include "MAIN.h"
#include "Grid.h"
#include "game_window.h"
extern GameWindow frame;
int iG::iScreenHeight=500;
int iG::iScreenWidth=940;
int iG::ifft;
double iG::iMouseDir;
double iG::iMouseX;
double iG::iMouseY;
int iG::ITimer::iAnimCount;
int iG::ITimer::iAnimDelays[10];
int iG::ITimer::iAnimPause[10];
void (*iG::ITimer::iAnimFunction[10])(void);

void iG::iResize()
{
	glViewport(0, 0,iScreenWidth,iScreenHeight);

	// glMatrixMode(GL_PROJECTION);
 //    glLoadIdentity();
 //    glOrtho(0.0, iScreenWidth, 0.0, iScreenHeight, -1.0, 1.0);
 //    glViewport(0.0, 0.0, iScreenWidth, iScreenHeight);
}
