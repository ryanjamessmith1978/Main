// Facade.cpp | https://www.youtube.com/watch?v=fsCof7BBHTs
// Facade Pattern: Occurs when you already have an interface, and you want to simplify it
// by having an interface on top of that interface.

// Facade is similar to adapter pattern
// Adapter tries to fit it to a specific situation for another interface.

#include <iostream>
#include "armorBuilderFacade.h" // the point is the facade contains armor class, don't need to #include "armor.h'

int main()
{
    // main.cpp doesn't need to know about the armor class, because facade handles armor interface
    ArmorBuilderFacade abf; 

    std::cout << abf.GetHeavyArmor() << '\n';
    std::cout << abf.GetMediumArmor() << '\n';
    std::cout << abf.GetLightArmor() << '\n';

    system("pause");
}
