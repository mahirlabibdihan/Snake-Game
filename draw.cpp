#include "iGraphics.h"
#include "game_window.h"
#include "MAIN.h"
#include "Snake.h"
#include "Food.h"
#include "Button.h"
#include "Box.h"
#include "game_details.h"
extern Button menu[5], level[2];
extern Box gameover[2];
extern Snake snake;
extern Food fruit;
extern GameWindow frame;
extern Option Menu;
extern GameDetails game;
void iG::iDraw()
{
	iClear();
	frame.draw();
	
	switch (Menu)
	{
	case NEW:
		// Grid::draw();
		snake.draw();
		fruit.draw();
		break;
	case MAIN:
		for (int i = NEW; i <= QUIT; i++)
		{
			menu[i].draw();
		}
		iG::ISetColor::iSolid(frame.border.getRGB());
		// iG::IDraw::iCircle(1000,1000,100);
		break;
	case LEVEL:
		for (int i = 0; i < 2; i++)
		{
			level[i].draw();
		}
		break;
	case GAMEOVER:
		for (int i = 0; i < 2; i++)
		{
			gameover[i].draw();
		}
		char Temp[10];
		itoa(game.getScore(), Temp, 10);
		iG::ISetColor::iSolid(WHITE);
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
		iG::ISetColor::iSolid(frame.border.getRGB());
		for(int i=0;!in.eof();i++)
		{
			char name[11],score[11];
			in >> name >> score;
			if (name != "")
			{
				iG::IText::iSmall(game.getScreenWidth()/3,game.getScreenHeight()-80-i*40,name);
				iG::IText::iSmall(2*game.getScreenWidth()/3,game.getScreenHeight()-80-i*40,score);
			}
		}
		in.close();

		break;
	}
}
