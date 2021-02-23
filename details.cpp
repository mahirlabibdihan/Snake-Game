#include "Details.h"
extern Food fruit;
extern Animal snake;
Details::Details()
	{
		gameOver = false;
		score = 0;
		increment = 10;
	}
	int Details::getScore()
	{
		return score;
	}
	void Details::incrementScore()
	{
		score += increment;
	}
	bool Details::isOver()
	{
		return gameOver;
	}
	void Details::save()
	{
		ofstream out;
		out.open("Data\\RESUME.txt", ios::out);
		snake.save(out);
		fruit.save(out);
		out << score << endl;
		out.close();

	}
	void Details::load()
	{
		ifstream in;
		in.open("Data\\RESUME.txt", ios::in);
		snake.load(in);
		fruit.load(in);
		in >> score;
		in.close();
	}
	void Details::Over()
	{
		gameOver = true;
	}
	void Details::reset()
	{
		gameOver = false;
		score = 0;
		snake.reset();
		fruit.newLocation();

	}