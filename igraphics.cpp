#include "main.h"
#include "Grid.h"
#include "game_window.h"
extern GameWindow frame;
int iG::iScreenHeight=500;
int iG::iScreenWidth;
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

void iG::iInitialize(char* title = (char*) "iG", int x = 0, int y = 10)
    {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA) ;
        glutInitWindowSize(iScreenWidth , iScreenHeight ) ;
        glutInitWindowPosition(x, y) ;
        glutCreateWindow(title) ;
        glClearColor( 0.0 , 0.0 , 0.0 , 0.0 ) ;
        glMatrixMode( GL_PROJECTION) ;
        glLoadIdentity() ;
        glOrtho(0.0 , iScreenWidth , 0.0 , iScreenHeight , -1.0 , 1.0) ;
        iClear();

        
        glutDisplayFunc(displayFF);
        glutReshapeFunc(reshapeFF);
        glutKeyboardFunc(keyboardHandler1FF); //normal
        glutSpecialFunc(keyboardHandler2FF); //special keys
        glutJoystickFunc(joystickHandlerFF,10);
        glutMouseFunc(mouseClickHandlerFF);
        glutMotionFunc(mouseDragHandlerFF);
        glutPassiveMotionFunc(mouseMoveHandlerFF);
        glutMouseWheelFunc(mouseWheelHandlerFF);
        glutIdleFunc(animFF) ;
        glAlphaFunc(GL_GREATER, 0.0f);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glLineWidth(2.0);
    }
