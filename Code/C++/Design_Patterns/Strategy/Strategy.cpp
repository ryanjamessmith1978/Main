// Strategy.cpp | https://www.youtube.com/watch?v=3I-C-Bu8pX4&list=PLalVdRk2RC6otl3oBU2cn-P6DWi1y1PS3&index=22
// Swap out algorithms or functions on the fly.
// When is it used?
// Simple Case?
// More advanced Case (overview)?

#include "strats.h"
#include "player.h"
#include <iostream>

int main() {
	char a;
	Level1Strategy l1;
	Level2Strategy l2;
	Level3Strategy l3;

	Player player1(&l1);

	std::cout << "Level 1 Melee Attack Damage: " << player1.MeleeAttack(1, 1) << '\n';
	std::cout << "Level 1 Ranged Attack Damage: " << player1.RangedAttack(1, 1) << '\n';

	std::cin >> a;
	std::cout << "level up!" << '\n';
	player1.SetStrat(&l2);

	std::cout << "Level 2 Melee Attack Damage: " << player1.MeleeAttack(1, 1) << '\n';
	std::cout << "Level 2 Ranged Attack Damage: " << player1.RangedAttack(1, 1) << '\n';
	std::cin >> a;

	std::cout << "level up!" << '\n';
	player1.SetStrat(&l3);

	std::cout << "Level 3 Melee Attack Damage: " << player1.MeleeAttack(1, 1) << '\n';
	std::cout << "Level 3 Ranged Attack Damage: " << player1.RangedAttack(1, 1) << '\n';

	system("pause");
}