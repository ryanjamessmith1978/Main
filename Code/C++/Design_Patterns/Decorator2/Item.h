//
// Item.h | example of a Decorator pattern
// Give Item an interface for games.

#pragma once
#include <string>

enum ITEMTYPE 
{   
    UNKNOWN, 
    ARMOR, 
    WEAPON 
};

// Standard Inheritance Model with an Abstract class as root.
class Item {
public:
    virtual ~Item() = default;
    virtual std::string GetName() const = 0;

    // Do we want to give people the option to give an item a name?  
    virtual void SetName(const std::string& new_name) { name = new_name; }

protected:
    Item(std::string n) : name(n) {}
    Item() = default;
    std::string name;
};

// Decorat-ee
class ConcreteWeapon : public Item {
public:
    ConcreteWeapon(const ConcreteWeapon&) = delete;
    ConcreteWeapon(ConcreteWeapon&&) = delete;
    ConcreteWeapon(std::string n, int d) : Item(n), damage(d) {}

    virtual std::string GetName() const override { return name; }
    int GetDamage() const { return damage; }

protected:
    int damage;
};

// Decorat-ee
class ConcreteArmor : public Item {
public:
    ConcreteArmor(const ConcreteArmor&) = delete;
    ConcreteArmor(ConcreteArmor&&) = delete;
    ConcreteArmor(std::string n, int dr) : Item(n), damage_res(dr) {}

    virtual std::string GetName() const override { return name; }

    int GetDamageRes() const { return damage_res; }

protected:
    int damage_res;
};

ITEMTYPE WhatIsItemType(Item* item) 
{
    auto* the_cast_to_armor = dynamic_cast<ConcreteArmor*>(item);
    if (the_cast_to_armor) {
        return ITEMTYPE::ARMOR;
    }

    auto* the_cast_to_weapon = dynamic_cast<ConcreteArmor*>(item);
    if (the_cast_to_weapon) {
        return ITEMTYPE::WEAPON;
    }

    return ITEMTYPE::UNKNOWN;
}

std::string WhatIsItemTypeString(Item* item) {
    auto* the_cast_to_armor = dynamic_cast<ConcreteArmor*>(item);
    if (the_cast_to_armor) {
        return "Armor";
    }

    auto* the_cast_to_weapon = dynamic_cast<ConcreteWeapon*>(item);
    if (the_cast_to_weapon) {
        return "Weapon";
    }

    return "Unknown";
}

// ### DECORATOR ###
// Adds functionality to classes that inherit from the same interface
// Generally contains a ptr to the base interface and through polymorphism
// is able to add this functionality to that brother/sister class.
// The Decorator itself becomes the final version of the class that is instantiated and used.

class MagicDecorator : public Item {
public:
    MagicDecorator(Item* item, int mod) : item_(item), magic_modifier_(mod) { }

    virtual void SetName(const std::string& new_name) override { magic_name_ = new_name; }
    
    virtual std::string GetName() const override 
    {
        std::string namestring = magic_name_; // if you use item_->GetName(), it'll use the base class's name.
        namestring += " | ";
        if (magic_modifier_ != 0) {
            namestring += (magic_modifier_ < 0) ? "-" : "+";
        }
        namestring += std::to_string(magic_modifier_) + " ";
        namestring += item_->GetName() + " | ";
        namestring += GetItemTypeString();
        return namestring;
    }

    std::string GetItemTypeString() const { return WhatIsItemTypeString(item_); }
    
    int GetMagicMod() { return magic_modifier_; }

// Decorator Properties
protected:
    Item* item_; // Pure interface, we're inheriting from it
                // Since weapon is an item, we can pass in weapon
    std::string magic_name_;
    int magic_modifier_;
};