#include "iGraphics.h"
#include "Window.h"
#include "MAIN.h"
#include "Animal.h"
#include "Food.h"
#include "Button.h"
#include "Box.h"
#include "Details.h"
extern Button menu[5], level[2];
extern Box gameover[2];
extern Animal snake;
extern Food fruit;
extern Window frame;
extern Option Menu;
extern Details game;
void iG::iDraw()
{
	iClear();
	frame.draw();
	switch (Menu)
	{
	case NEW:
		snake.draw();
		fruit.draw();
		break;
	case MAIN:
		for (int i = NEW; i <= QUIT; i++)
		{
			menu[i].draw();
		}
		break;
	case LEVEL:
		for (int i = 0; i < 2; i++)
		{
			level[i].draw();
		}
		break;
	case gameOver:
		for (int i = 0; i < 2; i++)
		{
			gameover[i].draw();
		}
		char Temp[10];
		itoa(game.getScore(), Temp, 10);
		iG::IsetColor::iSolid(WHITE);
		iG::IText::iSmall(gameover[0].getX() + 15, gameover[0].getY() + gameover[0].getHeight() / 3, Temp);
		if (!snake.name.empty())
		{
			char *temp = &snake.name[0];
			iG::IText::iSmall(gameover[1].getX() + 15, gameover[1].getY() + gameover[1].getHeight() / 3, temp);
		}
		break;

	case HIGHSCORE:
		ifstream in;
		in.open("Data\\HIGHSCORE.txt", ios::in);
		for(int i=0;!in.eof();i++)
		{
			char name[11],score[11];
			in >> name >> score;
			if (name != "")
			{
				iG::IText::iSmall(300,iG::iScreenHeight-80-i*40,name);
				iG::IText::iSmall(600,iG::iScreenHeight-80-i*40,score);
			}

		}
		in.close();

		break;
	}
}
