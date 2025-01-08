// Observer_Pattern.cpp | https://www.youtube.com/watch?v=rF3TfkknQK0
// Observer Design Pattern is a pattern that defines a one-to-many
// dependencies between objects so that when one object changes state,
// all it's dependents are notified and update automatically.
// Subject has list of observers.


#include <iostream>
#include <algorithm>
#include "car.h"
#include "observer.h"

int main()
{
    // subject
    car* c = new car();

    // observers - one car to many observers
    Leftobserver Leftobserver(c);
    Rightobserver rightobserver(c);
    Middleobserver middleobserver(c);

    cout << "hit left right button to drive a car in your city!!! and press break to close" << endl;

    char pressedButton;
    bool breakLoop = false;

    while (breakLoop == false) {
        cin >> pressedButton;

        switch (pressedButton) {
        case 108: { // l -->  pressed for left side
            c->setPosition(-1);
            break;
        }
        case 99: { // c --> pressed for center
            c->setPosition(0);
            break;
        }
        case 114: { // r --> pressed for right side
            c->setPosition(1);
            break;
        }
        case 98: { // b --> pressed for break
            breakLoop = true;
            break;
        }
        default: {
            cout << "please drive carfully!!" << endl;
            break;
        }
        }
    }
    cout << "Byee..." << endl;
    
    system("pause");
}

// There are observer classes that will be called when the subjects state changes
// Subjects have a list of observer classes.
// The subjects have event dispatchers that the observers listen for 
// when the subject's state changes and it sends out notifies.