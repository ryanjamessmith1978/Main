#pragma once
#include <iostream>

class IAnimal {
public:
    virtual ~IAnimal() = default;
    virtual void MakeSound() const = 0;
};

class Dog : public IAnimal {
public:
    virtual void MakeSound() const override {
        std::cout << "Wolf Bark Growl\n";
    }
};

// allows you to put in as a default parameter that gets passed into functions
// as your building the functionality out, and you want to have it exit before
// cascading to a bunch of other function calls, but still goes through call stack
// without crashing, linker/logic error checker.  
class NullAnimal : public IAnimal {
public:
    virtual void MakeSound() const override {}
};
