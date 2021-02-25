#include "Snake.h"
extern Button level[2];
extern GameDetails game;
extern Option Menu;
extern Food fruit;
bool isHighScore();
Direction dirKey = NONE;
Snake::Snake()
{
	head.setX(Grid::getCol() / 2);
	head.setY(Grid::getRow() / 2);
	head.setRadius(10);
	tail.push_back(head);
	length = 0;
}
int Snake::getDir()
{
	return this->dir;
}
int Snake::setDir(Direction A)
{
	this->dir = A;
}
int Snake::Length()
{
	return length;
}

void Snake::setName(string name)
{
	this->name = name;
}

void Snake::moveUp()
{
	head.changeY(1);
}
void Snake::moveDown()
{
	head.changeY(-1);
}
void Snake::moveLeft()
{
	head.changeX(-1);
}
void Snake::moveRight()
{
	head.changeX(1);
}
void Snake::stop() {
	this->pause = true;
}
void Snake::move() {
	this->pause = false;
}
bool Snake::isStopped()
{
	return this->pause;
}
void Snake::boundaryCheck()
{
	if (level[0].isSelected())
	{
		if (head.getX() > Grid::getCol() - 1)
		{
			head.setX(1);
		}
		else if (head.getY() > (Grid::getRow() - 1))
		{
			head.setY(1);
		}
		else if (head.getX() < 1)
		{
			head.setX(Grid::getCol() - 1);
		}
		else if (head.getY() < 1)
		{
			head.setY(Grid::getRow() - 1);
		}
	}
	else if (level[1].isSelected())
	{
		if (head.getX() > Grid::getCol() - 1)
		{
			Sleep(1000);
			if (isHighScore())
			{
				Menu = GAMEOVER;
			}
			else
			{
				Menu = MAIN;
			}
		}
		else if (head.getY() > (Grid::getRow() - 1))
		{
			Sleep(1000);
			if (isHighScore())
			{
				Menu = GAMEOVER;
			}
			else
			{
				Menu = MAIN;
			}
		}
		else if (head.getX() < 1)
		{
			Sleep(1000);
			if (isHighScore())
			{
				Menu = GAMEOVER;
			}
			else
			{
				Menu = MAIN;
			}
		}
		else if (head.getY() < 1)
		{
			Sleep(1000);
			if (isHighScore())
			{
				Menu = GAMEOVER;
			}
			else
			{
				Menu = MAIN;
			}
		}
	}
}
void Snake::insert()
{
	fruit.timer++;
	if (fruit.timer == 50) fruit.newLocation();
	tail.insert(tail.begin(), head);
	if (tail.size() > length)
	{
		tail.pop_back();
	}
}
void Snake::extend()
{
	length++;
}
void Snake::draw()
{
	iG::ISetColor::iTrans(head.getColor(), 0.5);
	iG::IDraw::iFilled::iCircle(head.getX()*Grid::getUnit(), head.getY()*Grid::getUnit(), head.getRadius());
	iG::ISetColor::iSolid(head.getColor());
	iG::IDraw::iCircle(head.getX()*Grid::getUnit(), head.getY()*Grid::getUnit(), head.getRadius());
	double Temp = 1;

	for (Circle i : tail)
	{
		iG::ISetColor::iTrans(head.getColor(), 0.5);
		iG::IDraw::iFilled::iCircle(i.getX()*Grid::getUnit(), i.getY()*Grid::getUnit(), head.getRadius() / Temp);
		iG::ISetColor::iSolid(head.getColor());
		iG::IDraw::iCircle(i.getX()*Grid::getUnit(), i.getY()*Grid::getUnit(), head.getRadius() / Temp);
		Temp += .01;
	}
}
void Snake::reset()
{
	tail.clear();
	length = 0;
	head.setPoint(Grid::getCol() / 2, Grid::getRow() / 2);
	dir = NONE;
	pause = false;
}
void Snake::save(ofstream& out)
{
	out << length << " " << dir << " " << pause << endl;
	head.save(out);
	for (int i = 0; i < length; i++)
	{
		tail[i].save(out);
	}
	out << endl;
}
void Snake::load(ifstream& in)
{
	in >> length >> dir >> pause;
	head.load(in);
	tail.resize(length);
	for (int i = 0; i < length; i++)
	{
		tail[i].load(in);
	}
	dirKey=(Direction)dir;
}

void Snake::controlMove(unsigned char key)
{
	switch (key)
		{
		case GLUT_KEY_UP:
			
			if (getDir() != DOWN)
			{
				dirKey = UP;
			}
			break;
		case GLUT_KEY_DOWN:
			if (getDir() != UP)
			{
				dirKey = DOWN;
			}
			break;
		case GLUT_KEY_LEFT:
			if (getDir() != RIGHT)
			{
				dirKey = LEFT;
			}
			break;
		case GLUT_KEY_RIGHT:
			if (getDir() != LEFT)
			{
				dirKey = RIGHT;
			}
			break;
		}
}