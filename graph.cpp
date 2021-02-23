#include "Graph.h"
Graph::Graph()
{

}
int Graph::getUnit()
{
	return unit;
}

int Graph::getRow()
{
	return row;
}

void Graph::setRow()
{
	row = iG::igetScreenHeight() / unit;
}
int Graph::getCol()
{
	return col;
}
void Graph::setCol()
{
	col = iG::igetScreenWidth() / unit;
}
int Graph::unit=20;
int Graph::row=iG::igetScreenHeight() / unit;
int Graph::col=iG::igetScreenWidth() / unit;