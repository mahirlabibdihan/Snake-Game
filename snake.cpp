#include "Snake.h"
extern Button level[2];
extern GameDetails game;
extern Option Menu;
extern Food fruit;

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
		this->pause=true;
	}
	void Snake::move() {
		this->pause=false;
	}
	bool Snake::isStopped()
	{
		return this->pause;
	}
	void Snake::boundaryCheck()
	{
		if(level[0].isSelected())
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
		else if(level[1].isSelected())
		{
			if (head.getX() > Grid::getCol() - 1)
			{
				Menu = GAMEOVER;
			}
			else if (head.getY() > (Grid::getRow() - 1))
			{
				Menu = GAMEOVER;
			}
			else if (head.getX() < 1)
			{
				Menu = GAMEOVER;
			}
			else if (head.getY() < 1)
			{
				Menu = GAMEOVER;
			}
		}
	}
	void Snake::insert()
	{
		fruit.timer++;
		if(fruit.timer==50) fruit.newLocation();
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
		iG::ISetColor::iTrans(head.getRGB(), 0.5);
		iG::IDraw::iFilled::iCircle(head.getX()*Grid::getUnit(), head.getY()*Grid::getUnit(), head.getRadius());
		iG::ISetColor::iSolid(head.getRGB());
		iG::IDraw::iCircle(head.getX()*Grid::getUnit(), head.getY()*Grid::getUnit(), head.getRadius());
		double Temp = 1;

		for (Circle i : tail)
		{
			iG::ISetColor::iTrans(head.getRGB(), 0.5);
			iG::IDraw::iFilled::iCircle(i.getX()*Grid::getUnit(), i.getY()*Grid::getUnit(), head.getRadius() / Temp);
			iG::ISetColor::iSolid(head.getRGB());
			iG::IDraw::iCircle(i.getX()*Grid::getUnit(), i.getY()*Grid::getUnit(), head.getRadius() / Temp);
			Temp += .01;
		}
	}
	void Snake::reset()
	{
		tail.clear();
		length = 0;
		head.setPoint(Grid::getCol() / 2, Grid::getRow() / 2);
		dir = 0;
	}
	void Snake::save(ofstream& out)
	{
		out << length << " " << dir << " "<<pause<<endl;
		head.save(out);
		for (int i = 0; i < length; i++)
		{
			tail[i].save(out);
		}
		out << endl;
	}
	void Snake::load(ifstream& in)
	{
		in >> length >> dir>>pause;
		head.load(in);
		tail.resize(length);
		for (int i = 0; i < length; i++)
		{
			tail[i].load(in);
		}
	}
