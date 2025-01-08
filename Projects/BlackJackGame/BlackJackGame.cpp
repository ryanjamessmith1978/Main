// BlackJackGame.cpp :
// Line 33 begins the main game loop
// This is copyrighted to this guy Xoax - he's cool


#include <iostream>
#include <ctime>

void Shuffle(bool baCardsDealt[]);
void PrintCard(int iCard);
void PrintHand(int iaHand[], const int kiCardCount);
int GetNextCard(bool baCardsDealt[]);
int ScoreHand(int iaHand[], const int kiCardCount);
void PrintScoresAndHands(int iaHouseHand[], const int kiHouseCardCount, int iaPlayerHand[], const int kiPlayerCardCount);

int main() {
	using namespace std;
	// Seed the random number generator
	time_t qTime;
	time(&qTime);
	srand(qTime);

	bool baCardsDealt[52];
	int iHouseCardCount = 0;
	int iaHouseHand[12];
	int iPlayerCardCount = 0;
	int iaPlayerHand[12];

	// Loop once for each hand
	while (true) {
		// "Shuffle" the cards; set them all to undealt
		Shuffle(baCardsDealt);
		// Deal the hands. Get two cards for each
		iaPlayerHand[0] = GetNextCard(baCardsDealt);
		iaHouseHand[0] = GetNextCard(baCardsDealt);
		iaPlayerHand[1] = GetNextCard(baCardsDealt);
		iaHouseHand[1] = GetNextCard(baCardsDealt);
		iHouseCardCount = 2;
		iPlayerCardCount = 2;

		// Signal a new hand.
		cout << "--------------------------------------------------------" << endl;
		cout << "-----------------------New Hand-------------------------" << endl;
		cout << "--------------------------------------------------------" << endl;

		char cPlayerChoice;
		bool bPlayerHits = true;
		int iPlayerScore = ScoreHand(iaPlayerHand, iPlayerCardCount);
		// Get Player's hits. Calculate the score and redisplay after each hit.
		do {
			// Print the dealt cards, but only the House's second card.
			cout << "House's Hand" << endl;
			cout << "** ";
			PrintCard(iaHouseHand[1]);
			cout << endl;
			cout << "Player's Hand: Score = " << ScoreHand(iaPlayerHand, iPlayerCardCount) << endl;
			PrintHand(iaPlayerHand, iPlayerCardCount);

			// Ask the Player whether he wants a hit or to stay
			cout << "Hit(h) or stay(s): ";
			cin >> cPlayerChoice;
			if (cPlayerChoice == 'h') {
				iaPlayerHand[iPlayerCardCount] = GetNextCard(baCardsDealt);
				++iPlayerCardCount;
			}
			else if (cPlayerChoice == 's') {
				bPlayerHits = false;
			}
			else {
				cout << "Error: Try Again!" << endl;
			}
			cout << endl;
			// Get the Player's current score to update and check for bust.
			iPlayerScore = ScoreHand(iaPlayerHand, iPlayerCardCount);
		} while (bPlayerHits && iPlayerScore < 22);

		// Once the player is done taking hits, check whether he busted
		if (iPlayerScore > 21) {
			// The Player busted. The House wins.
			cout << "**** The House Wins!!! ****" << endl;
			PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
		}
		else {
			// If the player didn't bust, then the house takes hits below 17
			int iHouseScore = ScoreHand(iaHouseHand, iHouseCardCount);
			while (iHouseScore < 17) {
				iaHouseHand[iHouseCardCount] = GetNextCard(baCardsDealt);
				++iHouseCardCount;
				iHouseScore = ScoreHand(iaHouseHand, iHouseCardCount);
			}
			bool bHouseBusts = (iHouseScore > 21);
			if (bHouseBusts) {
				// The House busted. Player wins
				cout << "**** The Player Wins!!! ****" << endl;
				PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
			}
			else {
				// Compare scores and determine the winner
				if (iPlayerScore == iHouseScore) {
					// Tie. This is called a "push."
					cout << "**** Tie!!! ****" << endl;
					PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
				}
				else if (iPlayerScore > iHouseScore) {
					// The Player wins
					cout << "**** The Player Wins!!! ****" << endl;
					PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
				}
				else {
					// The House wins
					cout << "**** The House Wins!!! ****" << endl;
					PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
				}
			}
		}
	}
	return EXIT_SUCCESS;
}

void Shuffle(bool baCardsDealt[]) {
	for (int iIndex = 0; iIndex < 52; ++iIndex) {
		baCardsDealt[iIndex] = false;
	}
}

void PrintCard(int iCard) {
	using namespace std;
	// Print Rank
	const int kiRank = (iCard % 13);
	if (kiRank == 0) {
		cout << 'A';
	}
	else if (kiRank < 9) {
		cout << (kiRank + 1);
	}
	else if (kiRank == 9) {
		cout << 'T';
	}
	else if (kiRank == 10) {
		cout << 'J';
	}
	else if (kiRank == 11) {
		cout << 'Q';
	}
	else {
		cout << 'K';
	}
	// Print Suit
	const int kiSuit = (iCard / 13);
	if (kiSuit == 0) {
		cout << 'C';
	}
	else if (kiSuit == 1) {
		cout << 'D';
	}
	else if (kiSuit == 2) {
		cout << 'H';
	}
	else {
		cout << 'S';
	}
}

void PrintHand(int iaHand[], const int kiCardCount) {
	using namespace std;
	for (int iCardIndex = 0; iCardIndex < kiCardCount; ++iCardIndex) {
		const int kiNextCard = iaHand[iCardIndex];
		PrintCard(kiNextCard);
		cout << " ";
	}
	cout << endl;
}

int GetNextCard(bool baCardsDealt[]) {
	bool bCardDealt = true;
	int iNewCard = -1;
	do {
		iNewCard = (rand() % 52);
		if (!baCardsDealt[iNewCard]) {
			bCardDealt = false;
		}
	} while (bCardDealt);
	return iNewCard;
}

int ScoreHand(int iaHand[], const int kiCardCount) {
	int iAceCount = 0;
	int iScore = 0;
	for (int iCardIndex = 0; iCardIndex < kiCardCount; ++iCardIndex) {
		const int kiNextCard = iaHand[iCardIndex];
		const int kiRank = (kiNextCard % 13);
		if (kiRank == 0) {
			++iAceCount;
			++iScore;
		}
		else if (kiRank < 9) {
			iScore = iScore + (kiRank + 1);
		}
		else {
			iScore = iScore + 10;
		}
	}
	while (iAceCount > 0 && iScore < 12) {
		--iAceCount;
		iScore = iScore + 10;
	}
	return iScore;
}

void PrintScoresAndHands(int iaHouseHand[], const int kiHouseCardCount, int iaPlayerHand[], const int kiPlayerCardCount) {
	using namespace std;
	cout << "House's Hand: Score = " << ScoreHand(iaHouseHand, kiHouseCardCount) << endl;
	PrintHand(iaHouseHand, kiHouseCardCount);
	cout << "Player's Hand: Score = " << ScoreHand(iaPlayerHand, kiPlayerCardCount) << endl;
	PrintHand(iaPlayerHand, kiPlayerCardCount);
	cout << endl;
}