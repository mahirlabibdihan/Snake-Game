#include "game_details.h"
extern Food fruit;
extern Snake snake;
GameDetails::GameDetails()
	{
		GAMEOVER = false;
		score = 0;
		increment = 10;
		screenHeight = iG::iGetScreenHeight();
		screenWidth = iG::iGetScreenWidth();
	}
	int GameDetails::getScreenHeight()
	{
		return screenHeight;
	}
	int GameDetails::getScreenWidth()
	{
		return screenWidth;
	}
	int GameDetails::getScore()
	{
		return score;
	}
	void GameDetails::incrementScore()
	{
		score += increment;
	}
	bool GameDetails::isOver()
	{
		return GAMEOVER;
	}
	void GameDetails::save()
	{
		ofstream out;
		out.open("Data\\RESUME.txt", ios::out);
		snake.save(out);
		fruit.save(out);
		out << score << endl;
		out.close();

	}
	void GameDetails::load()
	{
		ifstream in;
		in.open("Data\\RESUME.txt", ios::in);
		snake.load(in);
		fruit.load(in);
		in >> score;
		in.close();
	}
	void GameDetails::Over()
	{
		GAMEOVER = true;
	}
	void GameDetails::reset()
	{
		GAMEOVER = false;
		score = 0;
		snake.reset();
		fruit.newLocation();

	}