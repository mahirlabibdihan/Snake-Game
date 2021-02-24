#include "main.h"
#include "snake.h"
#include "game_details.h"
extern GameDetails game;
extern Snake snake;
struct ScoreType
	{
		string name;
		int score;
	};
void saveScore()
{
	
	vector<ScoreType> ScoreSheet;
	int i, j, k;
	ifstream in;
	in.open("Data\\HIGHSCORE.txt", ios::in);
	while (!in.eof())
	{
		string name;
		int score;
		in >> name >> score;
		if (name != "")
		{
			ScoreSheet.push_back({name, score});
		}
	}
	in.close();

	for (j = 0; j < ScoreSheet.size(); j++)
	{
		if (game.getScore() > ScoreSheet[j].score)
		{
			ScoreSheet.insert(ScoreSheet.begin() + j, (ScoreType) {snake.name, game.getScore()});
			break;
		}
	}
	if (j == ScoreSheet.size() && j < 10)
	{
		ScoreSheet.push_back({snake.name, game.getScore()});
	}
	ofstream out;
	out.open("Data\\HIGHSCORE.txt", ios::out);
	for (i = 0; i < ScoreSheet.size() - 1&&i<9; i++)
	{
		out << ScoreSheet[i].name << " " << ScoreSheet[i].score << endl;
	}
	out << ScoreSheet[i].name << " " << ScoreSheet[i].score;
	out.close();
}

bool isHighScore()
{
	vector<ScoreType> ScoreSheet;
	int i, j, k;
	ifstream in;
	in.open("Data\\HIGHSCORE.txt", ios::in);
	while (!in.eof())
	{
		string name;
		int score;
		in >> name >> score;
		if (name != "")
		{
			ScoreSheet.push_back({name, score});
		}
	}
	in.close();

	for (j = 0; j < ScoreSheet.size(); j++)
	{
		if (game.getScore() > ScoreSheet[j].score)
		{
			return true;
		}
	}
	if (j == ScoreSheet.size() && j < 10)
	{
		return true;
	}

	return false;
}