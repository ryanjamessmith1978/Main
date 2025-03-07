#pragma once
#include <string>
#include <iostream>

// The abstract class defines a template method that contains a skeleton of some
// algorithm, composed of calls to abstract primitive operations.
// 
// Concrete subclasses should implement these operations, but leave the template method intact.
// Template pattern uses a interface to define functionality, a base algorithm

class IAbstractAI {
public:
    void BaseOperatrion() { // publicly run all your code, all your templates.
        ScanMap();
        MoveUnit();
        Attack();
    }

protected:
    // operations you have to go through as part of construction.  
    void ScanMap() {
        //std::cout << "base ai - scan map\n";
        Scanner();
    }

    void MoveUnit() {
        //std::cout << "base ai - move unit\n";
        Mover();
    }

    void Attack() {
        //std::cout << "base ai - attack\n";
        SpecialAttack();
    }

    virtual void Scanner() = 0;
    virtual void Mover() = 0;
    virtual void SpecialAttack() = 0;

    virtual void Special1() {}
    virtual void Special2() {}

};

class RangedAlly : public IAbstractAI {
public:

protected:

    // Inherited via IAbstractAI
    virtual void Scanner() override {
        std::cout << "RangedAlly SCANNER\n";
        EnemyInSight = (bool)ZOOR();
        if (EnemyInSight) {
            std::cout << " - Finds enemy in sight...\n";
        }
        else {
            std::cout << " - no enemy in sight...\n";

        }
    }

    virtual void Mover() override {
        if (EnemyInSight) {
            std::cout << " - moves to attack range\n";
            EnemyInRange = true;
        }
    }

    virtual void SpecialAttack() override {
        if (EnemyInSight && EnemyInRange) {
            std::cout << " - fires weapon\n";
            Special1();
            Special2();
        }
    }

    // attack with possible crit chance special
    virtual void Special1() override {
        if (amountcount < 1) {
            Reload();
        }
        else {
            auto roll = NTKR(1, 100);
            if (roll > 67) {
                std::cout << " - crits!\n";
            }
            else if (roll > 33) {
                std::cout << " - hits!\n";
            }
            else {
                std::cout << " - misses!\n";
            }
        }
    }

private:
    bool EnemyInSight = false;
    bool EnemyInRange = false;
    int amountcount = 4;
    void Reload() { amountcount = 4; }
};