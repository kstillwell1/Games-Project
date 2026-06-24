#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Player
{
private:
	std::string name;
	std::string title = "";
	int wins = 0, losses = 0, currWinStreak = 0;
	bool streaking = false;


public:
	Player(std::string theName)
		: name(theName)
		, title("")
		, wins(0)
		, losses(0)
		, currWinStreak(0)
	{
	};
	~Player() {};

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

class IGame
{
public:
	virtual void printBoard() = 0;
	virtual bool checkTie() = 0;
	virtual bool checkSpot(int spot) = 0;
	virtual void replace(bool turn) = 0;
	virtual bool checkWin() = 0;
	virtual void setBoard() = 0;
	virtual ~IGame() {}
};

class TTT : public IGame
{
private:

	char board[3][3];
	bool spotCheck[3][3];

public:

	void printBoard() override;
	bool checkTie() override;
	bool checkSpot(int spot) override;
	void replace(bool turn) override;
	bool checkWin() override;
	void setBoard() override;
};

class Connect4 : public IGame
{
private:
	char board[6][7];
	bool spotCheck[6][7];

public:
	void printBoard() override;
	bool checkTie() override;
	bool checkSpot(int spot) override;
	void replace(bool turn) override;
	bool checkWin() override;
	void setBoard() override;
};

class Game
{
private:
	bool turn = true;
	bool end = false;
	std::vector<Player> playerPool;
	bool endProgram = false;

	IGame* currentGame = nullptr;

	Player* currPlayer1 = nullptr;
	Player* currPlayer2 = nullptr;

	void playerPoolEntry();
	void welcomeMessage();
	void selectGame();
	void playerSelection();
	void updateStats(Player* currPlayerWin, Player* currPlayerLoss);
	void postGameQuestions();
	void gameLoop();

public:

	Game() {};
	~Game()
	{
		delete currentGame;
	}

	void runGame();
};
