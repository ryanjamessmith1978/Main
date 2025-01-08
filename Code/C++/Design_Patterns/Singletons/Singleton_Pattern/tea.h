#include <string>

// Name goes after struct keyword.
class Tea {
	std::string name;
	int cost;
	int strength;
	int quantity;

public:
		
	// default initializer typically good idea.
	Tea(std::string n, int c, int s, int q)
	{
		name = n;
		cost = c;
		strength = s;
		quantity = q;
	}	

private:

	Tea() {}

	static Tea m_Tea;
	
};