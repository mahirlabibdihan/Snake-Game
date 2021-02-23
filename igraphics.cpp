#include "MAIN.h"
#include "Graph.h"
#include "Window.h"
extern Window frame;
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
	const float ar = (float)iG::iScreenWidth/ iG::iScreenHeight;
	glViewport(0, 0, iG::iScreenWidth, iG::iScreenHeight);
	// glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	glutReshapeWindow(iG::iScreenWidth, iG::iScreenHeight);
	cout<<iG::iScreenWidth<<" "<<iG::iScreenHeight<<endl;
	// Graph::setRow();
	// Graph::setCol();
	// frame.border.setBounds(Graph::getUnit()/2,Graph::getUnit()/2,(Graph::getCol() - 1)*Graph::getUnit(),(Graph::getRow() - 1)*Graph::getUnit());
}
