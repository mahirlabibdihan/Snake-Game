#include "game_window.h"
void GameWindow::draw()
{
	iG::ISetColor::iSolid(border.getRGB());
	border.draw();
}