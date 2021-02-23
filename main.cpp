#include "Main.h"
#include "Button.h"
#include "Animal.h"
#include "Food.h"
#include "Window.h"
#include "Details.h"
#include "Box.h"

Button menu[5],level[2];
Box gameover[2];
Animal snake;
Food fruit;
Window frame;
Option Menu = MAIN;
Details game;

void Logic()
{
	switch (Menu)
	{
	case NEW:
		if (game.isOver()) return;
		if (snake.isStopped()) return;	
		for (int i = 1; i < snake.Length(); i++)
		{
			if (snake.tail[i].getX() == snake.head.getX() && snake.tail[i].getY() == snake.head.getY())
			{
				Menu=gameOver;
			}
		}		
		snake.insert();
		if (fruit.isEaten())
		{
			game.incrementScore();
			snake.extend();
			fruit.newLocation();
		}

		if (snake.getDir() == UP)
		{
			snake.upWard();
		}
		else if (snake.getDir() == DOWN)
		{
			snake.downWard();
		}
		else if (snake.getDir() == LEFT)
		{
			snake.leftWard();
		}
		else if (snake.getDir() == RIGHT)
		{
			snake.rightWard();
		}
		snake.boundaryCheck();
	}
}
void setup()
{
	string MenuBtn[] = {"New game", "Resume", "Level", "Highscore", "Quit"};
	string LevelBtn[] = {"Easy", "Hard"};
	snake.head.setRGB(GREEN);
	frame.border.setRGB(GREEN);
	frame.border.setBounds(Graph::getUnit()/2,Graph::getUnit()/2,(Graph::getCol() - 1)*Graph::getUnit(),(Graph::getRow() - 1)*Graph::getUnit());
	fruit.newLocation();
	menu[0].select();
	level[0].select();

	for (int i = QUIT; i > MAIN; i--)
	{
		menu[i].setBounds(iG::igetScreenWidth()/2-.5*140, 80 + (QUIT - i) * 70, 150, 50);
		menu[i].setRGB(GREEN);
	}

	for (int i = 1; i > -1; i--)
	{
		level[i].setBounds(iG::igetScreenWidth()/2-.5*140, 170 + (1 - i) * 110, 150, 50);
		level[i].setRGB(GREEN);
	}

	for (int i = 1; i > -1; i--)
	{
		gameover[i].setBounds(iG::igetScreenWidth()/2-.5*140, 170 + (1 - i) * 110, 150, 50);
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
	iG::ITimer::iset(70, Logic);
	iG::iInitialize(iG::igetScreenWidth(), iG::igetScreenHeight(), (char*)"snake", 960-iG::igetScreenWidth()/2,510-iG::igetScreenHeight()/2);
	// glutFullScreen();
	glutMainLoop();
}

	