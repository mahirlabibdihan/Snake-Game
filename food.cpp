#include "Food.h"
extern Snake snake;
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
		setX(1 + (rand() % (Grid::getCol() - 1)));
		setY(1 + (rand() % (Grid::getRow() - 1)));
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
	iG::ISetColor::iSolid(snake.head.getRGB());
	iG::IDraw::iCircle(getX()*Grid::getUnit(), getY()*Grid::getUnit(), snake.head.getRadius());

	if(timer%2==0)
	{
		iG::ISetColor::iSolid(random());
		iG::IDraw::iFilled::iCircle(getX()*Grid::getUnit(), getY()*Grid::getUnit(), getRadius());
	}
	
}