#include <string>

// Name goes after struct keyword.
struct Tea {
	std::string name;
	int cost;
	int strength;
	int quantity;

	// default initializer typically good idea.
	Tea(std::string n, int c, int s, int q) : name(n), cost(c), strength(s), quantity(q){}
};