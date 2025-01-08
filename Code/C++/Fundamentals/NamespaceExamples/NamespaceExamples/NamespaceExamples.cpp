// Namespace Essentials
// Nesting namespaces requires using the scope resolution operators

#include <iostream>
namespace NMyNamespace
{
    int iNumber = 1;
}

namespace NYourNamespace
{
    int iNumber = 2;
}

namespace NOuter
{
    void f()
    {
        std::cout << "In outer namespace" << std::endl;
    }

    namespace NInner
    {
        void g()
        {
            std::cout << "In inner namespace" << std::endl;
        }
    }
}

int main()
{
    using namespace std; // using directive - use all from namespace

    std::cout << NMyNamespace::iNumber << std::endl;
    std::cout << NYourNamespace::iNumber << std::endl;

    NOuter::f();
    NOuter::NInner::g(); // Nesting namespaces requires using the scope resolution operators
    system("pause");
}