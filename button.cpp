#include "Button.h"
Button::Button()
{
	selected = false;
	setRGB(GREEN);
}
Button::Button(string name)
{
	selected = false;
	this->name = name;
	setRGB(GREEN);
}
void Button::select()
{
	selected = true;
}
void Button::deSelect()
{
	selected = false;
}
bool Button::isSelected()
{
	return selected;
}
void Button::draw()
{
	if (isSelected())
	{
		iG::IsetColor::iTrans(getRGB(), .5);
		iG::IDraw::iFilled::iRectangle(x, y, width, height);
	}

	iG::IsetColor::iSolid(getRGB());
	iG::IDraw::iRectangle(x, y, width, height);
	iG::IsetColor::iSolid(WHITE);
	char *Temp = &name[0];
	iG::IText::iSmall(x + 15, y + height / 3, Temp);
}
void Button::setName(string name)
{
	this->name = name;
}