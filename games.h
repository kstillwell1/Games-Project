#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "player.h"

class Board
{
protected:
	char** board = nullptr;
	bool** spotCheck = nullptr;

	virtual ~Board() {};
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
	virtual ~IGame() {};
};

class TTT : public IGame , public Board
{
public:
	~TTT();

	void printBoard() override;
	bool checkTie() override;
	bool checkSpot(int spot) override;
	void replace(bool turn) override;
	bool checkWin() override;
	void setBoard() override;
};

class Connect4 : public IGame , public Board
{
public:
	~Connect4();

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

	Game();
	~Game();

	void runGame();
};
