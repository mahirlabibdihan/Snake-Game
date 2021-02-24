#include "MAIN.h"
#include "Snake.h"
#include "game_details.h"
#include "Button.h"
extern Snake snake;
extern GameDetails game;
extern Option Menu;
extern Button menu[5], level[2];
void nameEntry(unsigned char key);

void iG::iKeyboard(unsigned char key)
{
	switch (Menu)
	{
	case MAIN:
	{
		switch (key)
		{
		case '\r':
		{
			for (int i = NEW; i <= QUIT; i++)
			{
				if (menu[i].isSelected())
				{
					switch (i)
					{
					case NEW:
						game.reset();
						Menu = NEW;
						break;

					case QUIT:
						exit(-1);
						break;

					case RESUME:
						game.load();
						Menu = NEW;
						break;

					case LEVEL:
						Menu = LEVEL;
						break;

					case HIGHSCORE:
						Menu = HIGHSCORE;
						break;
					}
				}
			}
			break;
		}
		}
		break;
	}


	case NEW:
	{
		switch (key)
		{
		case '\r':
			snake.stop();
			game.save();
			Menu = MAIN;
			break;
		case ' ':
			if (snake.isStopped()) snake.move();
			else snake.stop();
			break;
		}
		break;
	}


	case LEVEL:
	{
		switch (key)
		{
		case '\r':
			Menu = MAIN;
			break;
		}
		break;
	}

	case GAMEOVER:
	{
		nameEntry(key);
		break;
	}
	case HIGHSCORE:
	{
		switch (key)
		{
		case '\r':
			Menu = MAIN;
			break;
		}
		break;
	}

	}
}

void iG::iSpecialKeyboard(unsigned char key)
{
	switch (Menu)
	{
	case MAIN:
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			for (int i = NEW; i <= QUIT; i++)
			{
				if (menu[i].isSelected())
				{
					if (i == NEW)
					{
						menu[NEW].deSelect();
						menu[QUIT].select();
					}
					else
					{
						menu[i].deSelect();
						menu[i - 1].select();
					}
					break;
				}
			}
			break;
		case GLUT_KEY_DOWN:
			for (int i = NEW; i <= QUIT; i++)
			{
				if (menu[i].isSelected())
				{
					if (i == QUIT)
					{
						menu[QUIT].deSelect();
						menu[NEW].select();
					}
					else
					{
						menu[i].deSelect();
						menu[i + 1].select();
					}
					break;
				}
			}
			break;
		}
		break;
	}

	case NEW:
	{
		if(snake.isStopped())
		{
			break;
		}
		snake.controlMove(key);
		break;
	}

	case LEVEL:
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			if (level[0].isSelected())
			{
				level[0].deSelect();
				level[1].select();
			}
			else if (level[1].isSelected())
			{
				level[1].deSelect();
				level[0].select();
			}
			break;

		case GLUT_KEY_DOWN:
			if (level[0].isSelected())
			{
				level[0].deSelect();
				level[1].select();
			}
			else if (level[1].isSelected())
			{
				level[1].deSelect();
				level[0].select();
			}
			break;

		}
		break;
	}
	}
}