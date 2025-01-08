// Decorator.cpp | https://www.youtube.com/watch?v=PrVhfdQ1WRk
// Decorator 2 

#include "item.h"
#include <iostream>

int main() {
	ConcreteWeapon weapon1("Basic Sword", 3); // can use with flyweight pattern, if weapon1 is const, use weapon1 everywhere?
	MagicDecorator magic_weapon1(&weapon1, 2);
	MagicDecorator x2_magic_weapon1(&magic_weapon1, 2);

	//magic_weapon1.SetName("Armageddon");

	std::cout << weapon1.GetName() << " damage: " << weapon1.GetDamage() << '\n';
	std::cout << magic_weapon1.GetName() << " damage: " << (weapon1.GetDamage() + magic_weapon1.GetMagicMod()) << '\n';
	//std::cout << x2_magic_weapon1.GetName() << " damage: " << (weapon1.GetDamage() + x2_magic_weapon1.GetMagicMod()) << '\n';

	//	MagicWeapon weapon2("Magic Sword", 3, 2);
	//  std::cout << weapon2.GetName() << " damage: " << weapon2.GetDamage() << '\n';

	system("pause");
}

// *** DECORATOR PATTERN NOTES ***
//
// Decorator pattern allows behavior to be added to an individual object, dynamically, 
// without affecting behavior of other object from the same class.
// Decorators support compositional construction versus top-down
// Decorators can support or augment the 'Facade' pattern.
// Dynamically adding and removing responsibilities.
// 'Facade' and 'Adapter' re-does the interface in a more simplified way (typically used with bringing in libraries).
//
// Concrete component is the one you decorate up.
// DEF: Authentification - countable and uncountable plural authentifications - the process of making
// or establishing as, authentic.
//
// When and Where?
// Use a decorator pattern when you start creating large numbers of inherited classes.
// Decorator allows you to create a few base classes and then have extensions/decorations to modify sub-classes.
// Extensions are dynamic that can be added or removed on the fly.
// 
// When not to use?
// When you are using polymorphism, sub weapon types are no longer created with decorator, 
// therefor, you couldn't create a base class pointer and use polymorphism to call sub-class overriden functions.
//
// 
