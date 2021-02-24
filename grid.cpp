#include "Grid.h"
Grid::Grid()
{

}
int Grid::getUnit()
{
	return unit;
}

int Grid::getRow()
{
	return row;
}

void Grid::setRow()
{
	row = iG::iGetScreenHeight() / unit;
}
int Grid::getCol()
{
	return col;
}
void Grid::setCol()
{
	col = iG::iGetScreenWidth() / unit;
}
void Grid::draw()
{
	iG::ISetColor::iTrans(WHITE, .1);
	for (int i = 0; i <= getCol(); i++)
	{
		int x = getUnit() * i;
		iG::IDraw::iLine(x, 0, x, getRow() * getUnit());
	}
	for (int i = 0; i <= getRow(); i++)
	{
		int y = Grid::getUnit() * i;
		iG::IDraw::iLine(0, y, getCol() * getUnit(), y);
	}
}
int Grid::unit=20;
int Grid::row=iG::iGetScreenHeight() / unit;
int Grid::col=iG::iGetScreenWidth() / unit;