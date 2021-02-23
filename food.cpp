#include "Food.h"
extern Animal snake;
Food::Food()
{
	setRadius(5);
	timer=0;
}

bool Food::isEaten()
{
	return getX() == snake.head.getX() && getY() == snake.head.getY();
}
void Food::newLocation()
{
	this->timer=0;
	bool Success = false;
	while (!Success)
	{
		Success = true;
		setX(1 + (rand() % (Graph::getCol() - 1)));
		setY(1 + (rand() % (Graph::getRow() - 1)));
		for (auto i : snake.tail)
		{
			if (i.getX() == getX() && i.getY() == getY())
			{
				Success = false;
				break;
			}
		}
	}
	setRGB(55 + rand() % 200, 55 + rand() % 200, 55 + rand() % 200 );
}
void Food::draw()
{
	iG::IsetColor::iSolid(snake.head.getRGB());
	iG::IDraw::iCircle(getX()*Graph::getUnit(), getY()*Graph::getUnit(), snake.head.getRadius());
	iG::IsetColor::iSolid(getRGB());
	iG::IDraw::iFilled::iCircle(getX()*Graph::getUnit(), getY()*Graph::getUnit(), getRadius());
}