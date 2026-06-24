#pragma once
#include <string>

class Player
{
private:
	std::string name;
	std::string title = "";
	int wins = 0, losses = 0, currWinStreak = 0;
	bool streaking = false;


public:
	Player(std::string theName);
	~Player();

	std::string getName();
	std::string getTitle();
	void setTitle(std::string newTitle);
	void addWin();
	void addLoss();
	int getWins();
	int getLosses();
	int getCurrWinStreak();
	void setCurrWinStreak(int amount);
	bool getStreaking();
	void setStreaking(bool flag);
};
