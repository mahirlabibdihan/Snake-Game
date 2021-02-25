#ifndef __I_GRAPHICS__
#define __I_GRAPHICS__
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <Gl/GLAux.h>
#include <windows.h>
#include <mmsystem.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <tuple>
#include <fstream>
#define PI (acos(-1.0))
using namespace std;
#pragma comment(lib,"opengl32.lib")
class iG {
protected:
    static void iClear()
    {
        glClear(GL_COLOR_BUFFER_BIT) ;
        glMatrixMode(GL_MODELVIEW) ;
        glClearColor(0, 0, 0, 0);
        glFlush();
    }
    virtual void iAbstract()=0;
    static int iScreenHeight, iScreenWidth;
    static double iMouseX, iMouseY;
    static double  iMouseDir;
public:
    static int ifft;
    static void iDraw();
    static void iKeyboard(unsigned char);
    static void iSpecialKeyboard(unsigned char);
    static void iMouseDrag(int, int);
    static void iMouseMove(int, int);
    static void iMouseClick(int button, int state, int x, int y);
    static void iMouseScroll(int dir);
    static void iResize();
    static int iGetScreenHeight()
    {
        return iScreenHeight;
    }
    static int iGetScreenWidth()
    {
        return iScreenWidth;
    }
    static int iSetScreenHeight(int height)
    {
        iScreenHeight=height;
    }
    static int iSetScreenWidth(int width)
    {
        iScreenWidth=width;
    }
    static double igetMouseX()
    {
        return iMouseX;
    }
    static double igetMouseY()
    {
        return iMouseY;
    }
    static void isetMouseX(double x)
    {
        glutWarpPointer(x,iMouseY);
    }
    static void isetMouseY(double y)
    {
        glutWarpPointer(iMouseX, y);
    }
    static void isetMouse(double x, double y)
    {
        glutWarpPointer(x, y);
    }
    static double getMouseDirection()
    {
        return iMouseDir;
    }
    static void iMouseDirection(int mx, int my)
    {
        int dx = mx  - iMouseX , dy = my - iMouseY ;
        double dir = (atan(abs(1.0 * dy / dx)) * 180) / acos(-1);
        if (dx >= 0 && dy >= 0)
        {
            iMouseDir = dir;
        }
        else if (dx >= 0 && dy < 0)
        {
            iMouseDir = 360 + dir;
        }
        else if (dx < 0 && dy >= 0)
        {
            iMouseDir = 180 + dir;
        }
        else if (dx < 0 && dy < 0)
        {
            iMouseDir = 180 + dir;
        }
    }
    static void reshapeFF(int width, int height)
    {
        iScreenWidth = width;
        iScreenHeight = height;
        iResize();
    }
    static void displayFF(void) 
    {
        iDraw();
        glutSwapBuffers() ;
    }

    static void animFF(void)
    {
        if (ifft == 0) {
            ifft = 1;
            iClear();
        }
        glutPostRedisplay();
    }

    static void joystickHandlerFF(unsigned int buttonMask, int x, int y, int z)
    {
        cout<<buttonMask<<" "<<x<<" "<<y<<" "<<z<<endl;
    }
    static void keyboardHandler1FF(unsigned char key, int x, int y)
    {
        iKeyboard(key);
        glutPostRedisplay();
    }
    static void keyboardHandler2FF(int key, int x, int y)
    {
        iSpecialKeyboard(key);
        glutPostRedisplay();
    }
    static void mouseDragHandlerFF(int mx, int my)
    {
        iMouseX = mx;
        iMouseY = iScreenHeight - my;
        iMouseDrag(iMouseX, iMouseY);
        glFlush();
    }

    static void mouseMoveHandlerFF(int mx, int my)
    {
        iMouseDirection(mx, iScreenHeight - my);
        iMouseX = mx;
        iMouseY = iScreenHeight - my;
        iMouseMove(iMouseX, iMouseY);
        glFlush();
    }

    static void mouseClickHandlerFF(int button, int state, int x, int y)
    {
        iMouseX = x;
        iMouseY = iScreenHeight - y;
        iMouseClick(button, state, iMouseX, iMouseY);
        glFlush();
    }

    static void mouseWheelHandlerFF(int button, int dir, int x, int y)
    {
        iMouseScroll(dir);
    }

    class IText {
    public:
        static void iSmall(double x, double y, char *str, void* font = GLUT_BITMAP_TIMES_ROMAN_24)
        {
            glRasterPos3d(x, y, 0);
            int i;
            for (i = 0; str[i]; i++) {
                glutBitmapCharacter(font, str[i]); //,GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_24
            }
        }

        static void iBig(double x, double y, char *str, void* font = GLUT_STROKE_ROMAN)
        {
            char *p;
            glPushMatrix();
            glTranslatef(x, y, 0);
            for (p = str; *p; p++)
                glutStrokeCharacter(font, *p);
            glPopMatrix();
        }
    };
    class ITimer {
    private:
        static void (*iAnimFunction[10])(void);
        static int iAnimCount;
        static int iAnimDelays[10];
        static int iAnimPause[10];
        static void  __stdcall iA0(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[0])iAnimFunction[0]();}
        static void  __stdcall iA1(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[1])iAnimFunction[1]();}
        static void  __stdcall iA2(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[2])iAnimFunction[2]();}
        static void  __stdcall iA3(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[3])iAnimFunction[3]();}
        static void  __stdcall iA4(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[4])iAnimFunction[4]();}
        static void  __stdcall iA5(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[5])iAnimFunction[5]();}
        static void  __stdcall iA6(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[6])iAnimFunction[6]();}
        static void  __stdcall iA7(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[7])iAnimFunction[7]();}
        static void  __stdcall iA8(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[8])iAnimFunction[8]();}
        static void  __stdcall iA9(HWND, unsigned int, unsigned int, unsigned long) {if (!iAnimPause[9])iAnimFunction[9]();}
    public:
        static int iSet(int msec, void (*f)(void))
        {
            int i = iAnimCount;

            if (iAnimCount >= 10) {printf("Error: Maximum number of already timer used.\n"); return -1;}

            iAnimFunction[i] = f;
            iAnimDelays[i] = msec;
            iAnimPause[i] = 0;

            if (iAnimCount == 0) SetTimer(0, 0, msec, iA0);
            if (iAnimCount == 1) SetTimer(0, 0, msec, iA1);
            if (iAnimCount == 2) SetTimer(0, 0, msec, iA2);
            if (iAnimCount == 3) SetTimer(0, 0, msec, iA3);
            if (iAnimCount == 4) SetTimer(0, 0, msec, iA4);

            if (iAnimCount == 5) SetTimer(0, 0, msec, iA5);
            if (iAnimCount == 6) SetTimer(0, 0, msec, iA6);
            if (iAnimCount == 7) SetTimer(0, 0, msec, iA7);
            if (iAnimCount == 8) SetTimer(0, 0, msec, iA8);
            if (iAnimCount == 9) SetTimer(0, 0, msec, iA9);
            iAnimCount++;

            return iAnimCount - 1;
        }
        static void iPause(int index) {
            if (index >= 0 && index < iAnimCount) {
                iAnimPause[index] = 1;
            }
        }

        static void iResume(int index) {
            if (index >= 0 && index < iAnimCount) {
                iAnimPause[index] = 0;
            }
        }
    };
    class ISetColor{
    public:
        static void iSolid(double r, double g, double b)
        {
            double mmx;
            mmx = r;
            if (g > mmx)mmx = g;
            if (b > mmx)mmx = b;
            mmx = 255;
            if (mmx > 0) {
                r /= mmx;
                g /= mmx;
                b /= mmx;
            }
            glColor3f(r, g, b);
        }

        static void iSolid(tuple<double, double, double> rgb)
        {
            double r = get<0>(rgb), g = get<1>(rgb), b = get<2>(rgb);
            double mmx;
            mmx = r;
            if (g > mmx)mmx = g;
            if (b > mmx)mmx = b;
            mmx = 255;
            if (mmx > 0) {
                r /= mmx;
                g /= mmx;
                b /= mmx;
            }
            glColor3f(r, g, b);
        }


        static void iTrans(double r, double g, double b, double a=1.0)
        {
            double mmx = 255;
            if (r > mmx)
                r = mmx;
            if (g > mmx)
                g = mmx;
            if (b > mmx)
                b = mmx;
            r /= mmx;
            g /= mmx;
            b /= mmx;
            glColor4f(r, g, b, a);
        }
        static void iTrans(tuple<double, double, double> rgb, double a=1.0)
        {
            double r = get<0>(rgb), g = get<1>(rgb), b = get<2>(rgb);
            double mmx = 255;
            if (r > mmx)
                r = mmx;
            if (g > mmx)
                g = mmx;
            if (b > mmx)
                b = mmx;
            r /= mmx;
            g /= mmx;
            b /= mmx;
            glColor4f(r, g, b, a);
        }
    };
    class IShowImage {
        static void BMP2(int x, int y, char filename[], int ignoreColor)
        {
            AUX_RGBImageRec *TextureImage;
            TextureImage = auxDIBImageLoad(filename);

            int i, j, k;
            int width = TextureImage->sizeX;
            int height = TextureImage->sizeY;
            int nPixels = width * height;
            int *rgPixels = new int[nPixels];

            for (i = 0, j = 0; i < nPixels; i++, j += 3)
            {
                int rgb = 0;
                for (int k = 2; k >= 0; k--)
                {
                    rgb = ((rgb << 8) | TextureImage->data[j + k]);
                }

                rgPixels[i] = (rgb == ignoreColor) ? 0 : 255;
                rgPixels[i] = ((rgPixels[i] << 24) | rgb);
            }

            glRasterPos2f(x, y);
            glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, rgPixels);

            delete []rgPixels;
            free(TextureImage->data);
            free(TextureImage);
        }


        static void BMP(int x, int y, char filename[])
        {
            BMP2(x, y, filename, -1 /* ignoreColor */);
        }
    } IShowImage;

    class IDraw {
    public:
        class iFilled{
        public:
            static void iPolygon(double x[], double y[], int n)
            {
                int i;
                if (n < 3)return;
                glBegin(GL_POLYGON);
                for (i = 0; i < n; i++) {
                    glVertex2f(x[i], y[i]);
                }
                glEnd();
            }
            static void iRectangle(double left, double bottom, double dx, double dy)
            {
                double xx[4], yy[4];
                double x1, y1, x2, y2;

                x1 = left;
                y1 = bottom;
                x2 = x1 + dx;
                y2 = y1 + dy;

                xx[0] = x1;
                yy[0] = y1;
                xx[1] = x2;
                yy[1] = y1;
                xx[2] = x2;
                yy[2] = y2;
                xx[3] = x1;
                yy[3] = y2;
                iPolygon(xx, yy, 4);
            }

            static void iTriangle(double x1 , double y1 , double x2 , double y2 , double x3 , double y3)
            {
                double x[] = {x1, x2, x3};
                double y[] = {y1, y2, y3};
                iPolygon(x, y, 3);
            }

            static void iCircle(double x, double y, double r, int slices = 100)
            {
                double t, dt, x1, y1, xp, yp;
                dt = 2 * PI / slices;
                xp = x + r;
                yp = y;
                glBegin(GL_POLYGON);
                for (t = 0; t <= 2 * PI; t += dt)
                {
                    x1 = x + r * cos(t);
                    y1 = y + r * sin(t);

                    glVertex2f(xp, yp);
                    xp = x1;
                    yp = y1;
                }
                glEnd();
            }
            static void iEllipse(double x, double y, double a, double b, int slices = 100)
            {
                double t, dt, x1, y1, xp, yp;
                dt = 2 * PI / slices;
                xp = x + a;
                yp = y;
                glBegin(GL_POLYGON);
                for (t = 0; t <= 2 * PI; t += dt)
                {
                    x1 = x + a * cos(t);
                    y1 = y + b * sin(t);
                    glVertex2f(xp, yp);
                    xp = x1;
                    yp = y1;
                }
                glEnd();
            }

        };
        static void iPoint(double x, double y, int size = 0)
        {
            int i, j;
            glBegin(GL_POINTS);
            glVertex2f(x, y);
            for (i = x - size; i < x + size; i++)
            {
                for (j = y - size; j < y + size; j++)
                {
                    glVertex2f(i, j);
                }
            }

            glEnd();
            //    iFilledCircle(x,y,size/2.0);
        }

        static void iLine(double x1, double y1, double x2, double y2)
        {
            glBegin(GL_LINE_STRIP);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glEnd();
        }


        static void iDashedLine(double x1, double y1, double x2, double y2,double gap=15)
        {

            int j;

            double dir = (atan(abs(1.0 * (y1 - y2) / (x1 - x2))) * 180) / acos(-1);

            if (dir > 45)
            {
                double m = 1.0 * (x1 - x2) / (y1 - y2);
                double c = x1 - y1 * m;
                for (j = min(y1, y2); j <= max(y1, y2) - gap; j += gap*2)
                {
                    glBegin(GL_LINE_STRIP);
                    glVertex2f(m * j + c, j);
                    glVertex2f(m * (j + gap) + c, j + gap);
                    glEnd();
                }
            }
            else
            {
                double m = 1.0 * (y1 - y2) / (x1 - x2);
                double c = y1 - x1 * m;
                for (j = min(x1, x2); j <= max(x1, x2) - gap; j += gap*2)
                {
                    glBegin(GL_LINE_STRIP);
                    glVertex2f(j, m * j + c);
                    glVertex2f(j + gap, m * (j + gap) + c);
                    glEnd();
                }
            }
        }


        static void iPolygon(double x[], double y[], int n)
        {
            int i;
            if (n < 3)return;
            glBegin(GL_LINE_STRIP);
            for (i = 0; i < n; i++) {
                glVertex2f(x[i], y[i]);
            }
            glVertex2f(x[0], y[0]);
            glEnd();
        }

        static void iTriangle(double x1 , double y1 , double x2 , double y2 , double x3 , double y3)
        {
            double x[] = {x1, x2, x3};
            double y[] = {y1, y2, y3};
            iPolygon(x, y, 3);
        }

        static void iRectangle(double left, double bottom, double dx, double dy)
        {
            double x1, y1, x2, y2;

            x1 = left;
            y1 = bottom;
            x2 = x1 + dx;
            y2 = y1 + dy;

            iLine(x1, y1, x2, y1);
            iLine(x2, y1, x2, y2);
            iLine(x2, y2, x1, y2);
            iLine(x1, y2, x1, y1);
        }


        static void iCircle(double x, double y, double r, int slices = 100)
        {
            double t, dt, x1, y1, xp, yp;
            dt = 2 * PI / slices;
            xp = x + r;
            yp = y;
            for (t = 0; t <= 2 * PI; t += dt)
            {
                x1 = x + r * cos(t);
                y1 = y + r * sin(t);
                iLine(xp, yp, x1, y1);
                xp = x1;
                yp = y1;
            }
        }

        static void iEllipse(double x, double y, double a, double b, int slices = 100)
        {
            double t, dt, x1, y1, xp, yp;
            dt = 2 * PI / slices;
            xp = x + a;
            yp = y;
            for (t = 0; t <= 2 * PI; t += dt)
            {
                x1 = x + a * cos(t);
                y1 = y + b * sin(t);
                iLine(xp, yp, x1, y1);
                xp = x1;
                yp = y1;
            }
        }


        static void iStrokeLine(int x1, int y1, int x2, int y2, int width)
        {

            int j;

            double dir = (atan(abs(1.0 * (y1 - y2) / (x1 - x2))) * 180) / acos(-1);


            if (dir > 45)
            {
                double m = 1.0 * (x1 - x2) / (y1 - y2);
                double c = x1 - y1 * m;
                for (j = min(y1, y2); j <= max(y1, y2); j++)
                {
                    iPoint(m * j + c, j, width);
                }
            }
            else
            {
                double m = 1.0 * (y1 - y2) / (x1 - x2);
                double c = y1 - x1 * m;
                for (j = min(x1, x2); j <= max(x1, x2); j++)
                {
                    iPoint(j, m * j + c, width);
                }
            }
        }

        static void iStrokeCircle(int x, int y, int r, int width)
        {
            int i;
            for (i = r + width / 2; i > r - width / 2; i--)
            {
                iCircle(x, y, i);
            }
        }
    };

    static void iDelay(int sec)
    {
        int t1, t2;
        t1 = time(0);
        while (1) {
            t2 = time(0);
            if (t2 - t1 >= sec)
                break;
        }
    }

    static void igetPixelColor (int cursorX, int cursorY, int rgb[])
    {
        GLubyte pixel[3];
        glReadPixels(cursorX, cursorY, 1, 1,
                     GL_RGB, GL_UNSIGNED_BYTE, (void *)pixel);

        rgb[0] = pixel[0];
        rgb[1] = pixel[1];
        rgb[2] = pixel[2];

        //printf("%d %d %d\n",pixel[0],pixel[1],pixel[2]);
    }
    static void iRotate(double x, double y, double degree)
    {
        // push the current matrix stack
        glPushMatrix();

        //
        // The below steps take effect in reverse order
        //

        // step 3: undo the translation
        glTranslatef(x, y, 0.0);

        // step 2: rotate the co-ordinate system across z-axis
        glRotatef(degree, 0, 0, 1.0);

        // step 1: translate the origin to (x, y)
        glTranslatef(-x, -y, 0.0);
    }

    static void iUnRotate()
    {
        glPopMatrix();
    }

    static void iInitialize(char* title, int x, int y);
};

#endif









