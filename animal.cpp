#include "Animal.h"
extern Button level[2];
extern Details game;
extern Option Menu;
extern Food fruit;

Animal::Animal()
	{
		head.setX(Graph::getCol() / 2);
		head.setY(Graph::getRow() / 2);
		head.setRadius(10);
		tail.push_back(head);
		length = 0;
	}
	int Animal::getDir()
	{
		return this->dir;
	}
	int Animal::setDir(Direction A)
	{
		this->dir = A;
	}
	int Animal::Length()
	{
		return length;
	}

	void Animal::setName(string name)
	{
		this->name = name;
	}

	void Animal::upWard()
	{
		head.changeY(1);
	}
	void Animal::downWard()
	{
		head.changeY(-1);
	}
	void Animal::leftWard()
	{
		head.changeX(-1);
	}
	void Animal::rightWard()
	{
		head.changeX(1);
	}
	void Animal::stop() {
		this->pause=true;
	}
	void Animal::move() {
		this->pause=false;
	}
	bool Animal::isStopped()
	{
		return this->pause;
	}
	void Animal::boundaryCheck()
	{
		if(level[0].isSelected())
		{
			if (head.getX() > Graph::getCol() - 1)
			{
				head.setX(1);
			}
			else if (head.getY() > (Graph::getRow() - 1))
			{
				head.setY(1);
			}
			else if (head.getX() < 1)
			{
				head.setX(Graph::getCol() - 1);
			}
			else if (head.getY() < 1)
			{
				head.setY(Graph::getRow() - 1);
			}
		}
		else if(level[1].isSelected())
		{
			if (head.getX() > Graph::getCol() - 1)
			{
				game.Over();
				game.reset();
				Menu = MAIN;
			}
			else if (head.getY() > (Graph::getRow() - 1))
			{
				game.Over();
				game.reset();
				Menu = MAIN;
			}
			else if (head.getX() < 1)
			{
				game.Over();
				game.reset();
				Menu = MAIN;
			}
			else if (head.getY() < 1)
			{
				game.Over();
				game.reset();
				Menu = MAIN;
			}
		}
	}
	void Animal::insert()
	{
		fruit.timer++;
		if(fruit.timer==50) fruit.newLocation();
		tail.insert(tail.begin(), head);
		if (tail.size() > length)
		{
			tail.pop_back();
		}
	}
	void Animal::extend()
	{
		length++;
	}
	void Animal::draw()
	{
		iG::IsetColor::iTrans(head.getRGB(), 0.5);
		iG::IDraw::iFilled::iCircle(head.getX()*Graph::getUnit(), head.getY()*Graph::getUnit(), head.getRadius());
		iG::IsetColor::iSolid(head.getRGB());
		iG::IDraw::iCircle(head.getX()*Graph::getUnit(), head.getY()*Graph::getUnit(), head.getRadius());
		double Temp = 1;

		for (Circle i : tail)
		{
			iG::IsetColor::iTrans(head.getRGB(), 0.5);
			iG::IDraw::iFilled::iCircle(i.getX()*Graph::getUnit(), i.getY()*Graph::getUnit(), head.getRadius() / Temp);
			iG::IsetColor::iSolid(head.getRGB());
			iG::IDraw::iCircle(i.getX()*Graph::getUnit(), i.getY()*Graph::getUnit(), head.getRadius() / Temp);
			Temp += .01;
		}
	}
	void Animal::reset()
	{
		tail.clear();
		length = 0;
		head.setXY(Graph::getCol() / 2, Graph::getRow() / 2);
		dir = 0;
	}
	void Animal::save(ofstream& out)
	{
		out << length << " " << dir << endl;
		head.save(out);
		for (int i = 0; i < length; i++)
		{
			tail[i].save(out);
		}
		out << endl;
	}
	void Animal::load(ifstream& in)
	{
		in >> length >> dir;
		head.load(in);
		tail.resize(length);
		for (int i = 0; i < length; i++)
		{
			tail[i].load(in);
		}
	}
