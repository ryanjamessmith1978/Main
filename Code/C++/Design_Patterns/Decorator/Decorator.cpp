// Decorator.cpp | https://www.youtube.com/watch?v=rtfDbdSV4a8

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "Shape.h"
#include "Webpage.h"

int main() {

    // shape test
    Circle circle;
    ColoredShape colored_shape("red", &circle);
    std::cout << colored_shape.GetName() << std::endl;
    auto* circle_casted = dynamic_cast<Circle*>(colored_shape.shape); // you would want casting hidding behind your classes.

    if (circle_casted) 
    {
        circle_casted->Resize(10.f);
        std::cout << "Resized!\n";
    }

    //webpage test
    std::unique_ptr<WebPage> myPage = std::make_unique<BasicWebPage>(); // makes a basicWebPage ptr, not an object, no constructor.

    myPage = std::make_unique<AuthorizedWebPage>(std::move(myPage));
    myPage = std::make_unique<AuthenticatedWebPage>(std::move(myPage));
    myPage->display();
    std::cout << std::endl;

    system("pause");
}
