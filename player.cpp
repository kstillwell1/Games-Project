#include "player.h"

Player::Player(std::string theName)
	: name(theName)
	, title("")
	, wins(0)
	, losses(0)
	, currWinStreak(0)
{
};

Player::~Player() {};

std::string Player::getName()
{
	return name;
}

std::string Player::getTitle()
{
	return title;
}

void Player::setTitle(std::string newTitle)
{
	title = newTitle;
}

void Player::addWin()
{
	wins++;
	currWinStreak++;
}

void Player::addLoss()
{
	losses++;
}

int Player::getWins()
{
	return wins;
}

int Player::getLosses()
{
	return losses;
}

int Player::getCurrWinStreak()
{
	return currWinStreak;
}

void Player::setCurrWinStreak(int amount)
{
	currWinStreak = amount;
}

bool Player::getStreaking()
{
	return streaking;
}

void Player::setStreaking(bool flag)
{
	streaking = flag;
}
