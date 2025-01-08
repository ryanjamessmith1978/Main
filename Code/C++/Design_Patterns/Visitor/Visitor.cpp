// Visitor.cpp | https://www.youtube.com/watch?v=IobXgpgqnYc&list=PLalVdRk2RC6otl3oBU2cn-P6DWi1y1PS3&index=12
//

#include "visitor.h"
#include <array>

int main() {
    std::array<const Component*, 3> components = { new ComponentA, new ComponentB, new ComponentC };
    Visitor1* v1 = new Visitor1;
    Visitor2* v2 = new Visitor2;

    for (const Component* comp : components) {
        comp->Accept(v1);
    }

    //for (const Component* comp : components) {
    //    comp->Accept(v2);
   // }

    // cleanup
    for (const Component* comp : components) {
        delete comp;
    }

    delete v1;
    delete v2;

    system("pause");
}


