#include "snake.h"
#include "main.h"
extern Snake snake;
extern Option Menu;
void saveScore();
void nameEntry(unsigned char key)
{
	switch (key)
		{
		case '\r':
			if (!snake.name.empty())
			{
				saveScore();
				snake.name.clear();
				Menu = MAIN;
			}
			break;
		case '\b':
			if (!snake.name.empty())
			{
				snake.name.pop_back();
			}
		case 27:
			// Menu = MAIN;
			break;
		case ' ':
			break;
		default:
			if (snake.name.length() < 10)
			{
				snake.name += key;
			}
			break;
		}
}
