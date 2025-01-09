#include <iostream>
#include <string>
#include <vector>

#include "Dice.h"
#include "Player.h"

using namespace std;

// Function Prototypes (Same as using header files but for main.cpp, since main doesn't generally use a header)
bool GameLoop(int PlayersTurn, int const TOTALPLAYERS);
int GetNumberOfPlayers();
void BuildPlayerObjectArray(int NumOfPlayers, int const TOTALPLAYERS);
Player& GetPlayerToLeft(int turn, int const TOTALPLAYERS);
Player& GetPlayerToRight(int turn, int const TOTALPLAYERS);

// Global variable for holding an array of player objects

std::vector<Player> Players;

int main()
{	
	// read instructions stream - function

	// prompts for number of players - function (if less than 3 keep asking for input)
	int NumOfPlayers = GetNumberOfPlayers();
	int const TOTALPLAYERS = NumOfPlayers;
		
	// Fills the global player object array with the amount of players entered - function def. below
	BuildPlayerObjectArray(NumOfPlayers, TOTALPLAYERS);

	bool bGameWon = false;
	int PlayerTurn = 0;
	// Main game loop while the game isn't won - function
	while (!bGameWon)
	{		
		bGameWon = GameLoop(PlayerTurn, TOTALPLAYERS);
		if (PlayerTurn == TOTALPLAYERS - 1)
		{
			PlayerTurn = 0;
		}
		else
		{ 
			PlayerTurn++;
		}
	}

	cout << Players[0].GetMaxNumberOfChips() << endl;
	// print game is won message - function
	return 0;
}

void BuildPlayerObjectArray(int NumOfPlayers, int const TOTALPLAYERS)
{
	// builds players object array based on that response	
	for (int i = 0; i < NumOfPlayers; i++)
	{
		Player CurrentPlayer(i, TOTALPLAYERS);
		Players.push_back(CurrentPlayer);
	}
}

bool GameLoop(int PlayersTurn, int const TOTALPLAYERS)
{
	bool GameWon = true;
	// create 3 dice objects
	Dice Dice1;
	Dice Dice2;
	Dice Dice3;
	// Determines Left and Right Players
	Player& LeftPlayer = GetPlayerToLeft(PlayersTurn, TOTALPLAYERS);
	Player& RightPlayer = GetPlayerToRight(PlayersTurn, TOTALPLAYERS);
	Player& CurrentPlayer = Players[PlayersTurn];

	// rolls dice
	int RollNumber1 = Dice1.CreateRollNumber();
	int RollNumber2 = Dice2.CreateRollNumber();
	int RollNumber3 = Dice3.CreateRollNumber();

	// if RollNumber 1 is 

	return GameWon;
}

int GetNumberOfPlayers()
{
	int NumOfPlayers = 0;
	while (NumOfPlayers < 3)
	{
		cout << "How many players will be playing: ";
		cin >> NumOfPlayers;

		if (NumOfPlayers < 3)
		{
			cout << "That is an invalid number of players, at least 3 players are required to play.";
			cout << endl << endl;
		}
	}
	return NumOfPlayers;
}

Player& GetPlayerToLeft(int turn, int const TOTALPLAYERS)
{
	Player& LeftPlayer = Players[turn - 1];

	if (turn == 0)
	{
		LeftPlayer = Players[TOTALPLAYERS - 1];
	}

	return LeftPlayer;
}

Player& GetPlayerToRight(int turn, int const TOTALPLAYERS)
{
	Player& RightPlayer = Players[turn + 1];

	if (turn == TOTALPLAYERS - 1)
	{
		RightPlayer = Players[0];
	}
	
	return RightPlayer;
}
