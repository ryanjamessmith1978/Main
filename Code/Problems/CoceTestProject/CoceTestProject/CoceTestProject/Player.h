#pragma once
// *** Player Class ***
// Holds number of chips


class Player
{
public:
	Player();
	Player(int PlayerNum, int NumberOfPlayers);
	~Player();

	// GetNumberOfChips function
	int GetNumberOfChips();
	// GetMaxNumberOfChips function
	int GetMaxNumberOfChips();
	// GetNumberOfRolls function
	int GetNumberOfRolls();

	// SetNumberOfChips function
	void SetNumberOfChips(int chips);
	// SetMaxNumberOfChips function
	void SetMaxNumberOfChips(int chips);
	// SetNumberOfRolls function
	void SetNumberOfRolls(int rolls);
	
private:

	int CurrentNumberOfChips;
	int MaxNumberOfChips;
	int NumberOfRolls;
	int PlayerNumber;
};

