#include "Player.h"

Player::Player()
{
	CurrentNumberOfChips = 0;
	MaxNumberOfChips = 0;
	NumberOfRolls = 0;
	PlayerNumber = 0;
}

Player::Player(int PlayerNum, int NumberOfPlayers)
{
	CurrentNumberOfChips = 3;
	MaxNumberOfChips = 3 * NumberOfPlayers;
	NumberOfRolls = 1;
	PlayerNumber = PlayerNum;
}

Player::~Player()
{
}

int Player::GetNumberOfChips()
{
	return CurrentNumberOfChips;
}

int Player::GetMaxNumberOfChips()
{
	return MaxNumberOfChips;
}

int Player::GetNumberOfRolls()
{
	return NumberOfRolls;
}

void Player::SetNumberOfChips(int chips)
{

}

void Player::SetMaxNumberOfChips(int chips)
{

}

void Player::SetNumberOfRolls(int rolls)
{

}
