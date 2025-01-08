#pragma once
#include <string>

// Armor Builder or a Facade for the Armor class.


// we want to 'Facade Over' the armor interface.
class Armor {
protected:
    virtual void donArmor() = 0;  // pure virtual
public:
    std::string ArmorType;
};

class HeavyArmor : public Armor {
    void donArmor() override {
        ArmorType = "Heavy";
    }
public:
    HeavyArmor() { donArmor(); }
};

class MediumArmor : public Armor {
    void donArmor() override {
        ArmorType = "Medium";
    }
public:
    MediumArmor() { donArmor(); }
};

class LightArmor : public Armor {
    void donArmor() override {
        ArmorType = "Light";
    }
public:
    LightArmor() { donArmor(); }
};