#include "main.h"
#include "Button.h"
#include "Snake.h"
#include "Food.h"
#include "game_window.h"
#include "game_details.h"
#include "Box.h"

Button menu[5],level[2];
Box gameover[2];
Snake snake;
Food fruit;
GameWindow frame;
Option Menu = MAIN;
GameDetails game;

extern Direction dirKey;
bool isHighScore();
bool Play=false;
void Logic()
{
	switch (Menu)
	{
	case NEW:
		if(!Play)
		{
			
			Play=true;
		}
		
		if (game.isOver()) return;
		if (snake.isStopped()) return;	
		if (dirKey==NONE) return;
		for (int i = 1; i < snake.Length(); i++)
		{
			if (snake.tail[i].getX() == snake.head.getX() && snake.tail[i].getY() == snake.head.getY())
			{
				Sleep(1000);
				if(isHighScore())
				{
					Menu = GAMEOVER;
				}
				else
				{
					Menu = MAIN;
				}
			}
		}		


		snake.insert();
		if (fruit.isEaten())
		{
			game.incrementScore();
			snake.extend();
			fruit.newLocation();
		}

		if (dirKey == UP)
		{
			snake.setDir(dirKey);
			snake.moveUp();
		}
		else if (dirKey == DOWN)
		{
			snake.setDir(dirKey);
			snake.moveDown();
		}
		else if (dirKey == LEFT)
		{
			snake.setDir(dirKey);
			snake.moveLeft();
		}
		else if (dirKey == RIGHT)
		{
			snake.setDir(dirKey);
			snake.moveRight();
		}
		snake.boundaryCheck();
	}
}
void setup()
{
	Grid::setUnit(20);
	iG::iSetScreenHeight(500);
	iG::iSetScreenWidth(ceil((GetSystemMetrics(SM_CXFULLSCREEN)*500.0)/(GetSystemMetrics(SM_CYFULLSCREEN)*Grid::getUnit()))*Grid::getUnit());
	Grid::setRow();
	Grid::setCol();
	game.setScreenHeight();
	game.setScreenWidth();
	string MenuBtn[] = {"New game", "Resume", "Level", "Highscore", "Quit"};
	string LevelBtn[] = {"Easy", "Hard"};
	snake.head.setRGB(GREEN);
	frame.border.setRGB(GREEN);
	
	frame.border.setBounds(Grid::getUnit()/2,Grid::getUnit()/2,(Grid::getCol() - 1)*Grid::getUnit(),(Grid::getRow() - 1)*Grid::getUnit());
	fruit.newLocation();
	menu[0].select();
	level[0].select();

	for (int i = QUIT; i > MAIN; i--)
	{
		menu[i].setBounds(iG::iGetScreenWidth()/2-.5*140, 80 + (QUIT - i) * 70, 150, 50);
		menu[i].setRGB(GREEN);
	}

	for (int i = 1; i > -1; i--)
	{
		level[i].setBounds(iG::iGetScreenWidth()/2-.5*140, 170 + (1 - i) * 110, 150, 50);
		level[i].setRGB(GREEN);
	}

	for (int i = 1; i > -1; i--)
	{
		gameover[i].setBounds(iG::iGetScreenWidth()/2-.5*140, 170 + (1 - i) * 110, 150, 50);
		gameover[i].setRGB(GREEN);
	}

	for (int i = NEW; i <= QUIT; i++)
	{
		menu[i].setName(MenuBtn[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		level[i].setName(LevelBtn[i]);
	}
}

int main(int argc, char *argv[])
{

	srand(time(NULL));
	glutInit(&argc, argv);
	setup();
	iG::ITimer::iSet(50, Logic);
	iG::iInitialize((char*)"snake",GetSystemMetrics(SM_CXFULLSCREEN)/2-iG::iGetScreenWidth()/2,GetSystemMetrics(SM_CYFULLSCREEN)/2-iG::iGetScreenHeight()/2);
	// glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);
	glutMainLoop();


}

	