#include "MAIN.h"
#include "Animal.h"
#include "Details.h"
#include "Button.h"
extern Animal snake;
extern Details game;
extern Option Menu;
extern Button menu[5], level[2];

void SaveScore()
{
	struct ScoreType
	{
		string name;
		int score;
	};
	vector<ScoreType> ScoreSheet;
	int i, j, k;
	ifstream in;
	in.open("Data\\HIGHSCORE.txt", ios::in);
	while (!in.eof())
	{
		string name;
		int score;
		in >> name >> score;
		if (name != "")
		{
			ScoreSheet.push_back({name, score});
		}
	}
	cout << ScoreSheet.size() << endl;
	in.close();

	for (j = 0; j < ScoreSheet.size(); j++)
	{
		if (game.getScore() > ScoreSheet[j].score)
		{
			ScoreSheet.insert(ScoreSheet.begin() + j, (ScoreType) {snake.name, game.getScore()});
			break;
		}
	}
	if (j == ScoreSheet.size() && j < 10)
	{
		ScoreSheet.push_back({snake.name, game.getScore()});
	}
	ofstream out;
	out.open("Data\\HIGHSCORE.txt", ios::out);
	for (i = 0; i < ScoreSheet.size() - 1&&i<9; i++)
	{
		out << ScoreSheet[i].name << " " << ScoreSheet[i].score << endl;
	}
	out << ScoreSheet[i].name << " " << ScoreSheet[i].score;
	out.close();
}

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
			snake.setDir(NONE);
			game.Over();
			game.save();
			game.reset();
			Menu = MAIN;
			break;
		case ' ':
			if(snake.isStopped()) snake.move();
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

	case gameOver:
	{
		switch (key)
		{
		case '\r':
			SaveScore();
			Menu = MAIN;
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
	switch (key)
	{
	case GLUT_KEY_END:
		exit(0);
		break;

	case GLUT_KEY_UP:
		switch (Menu)
		{
		case MAIN:
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
		case NEW:
			if (snake.getDir() != DOWN)
			{
				snake.setDir(UP);
			}
			break;

		case LEVEL:
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

	case GLUT_KEY_DOWN:
		switch (Menu)
		{
		case MAIN:
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
		case NEW:
			if (snake.getDir() != UP)
			{
				snake.setDir(DOWN);
			}
			break;
		case LEVEL:
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

	case GLUT_KEY_LEFT:
		switch (Menu)
		{
		case NEW:
			if (snake.getDir() != RIGHT)
			{
				snake.setDir(LEFT);
			}
			break;

		}

		break;

	case GLUT_KEY_RIGHT:
		switch (Menu)
		{
		case NEW:
			if (snake.getDir() != LEFT)
			{
				snake.setDir(RIGHT);
			}
			break;
		}
		break;
	}
}