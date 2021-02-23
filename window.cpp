#include "Window.h"
void Window::draw()
{
	iG::IsetColor::iTrans(WHITE, .1);
	for (int i = 0; i <= Graph::getCol(); i++)
	{
		int x = Graph::getUnit() * i;
		iG::IDraw::iLine(x, 0, x, Graph::getRow() * Graph::getUnit());
	}
	for (int i = 0; i <= Graph::getRow(); i++)
	{
		int y = Graph::getUnit() * i;
		iG::IDraw::iLine(0, y, Graph::getCol() * Graph::getUnit(), y);
	}
	iG::IsetColor::iSolid(border.getRGB());
	border.draw();
}