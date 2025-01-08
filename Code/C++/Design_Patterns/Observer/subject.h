#pragma once
#include "subscriber.h"
#include <list>

// A pattern to allow notifications to be sent to anyone who subscribes.
// Overall the point is to not have users manually check something,
// but rather be sent a notification whenever a certain event happens 
// to a subject. 

// Need a publishing service (subject).  Something that goes with your business logic.
// Need an array of all the subscribers / observers.
class SubjectInterface {
public:
    virtual ~SubjectInterface() {};
    virtual void Add(SubscriberInterface* sub) = 0; // pointers make it easy to move observers around.
    virtual void Remove(SubscriberInterface* sub) = 0;
    virtual void Notify() = 0;
};

class Subject : public SubjectInterface {
public:
    // List is great because we can use simple methods with low overhead from the STL.
    void Add(SubscriberInterface* sub) override {
        _subs.push_back(sub);
    };
    void Remove(SubscriberInterface* sub) override {
        _subs.remove(sub);
    };
    void Notify() override {
        if (_subs.empty())
            return;
        std::list<SubscriberInterface*>::iterator it = _subs.begin();
        while (it != _subs.end()) {
            (*it)->Update(_latest_message);
            it++;
        }
    };

    void AdvanceAndUpdateAll() {
        static int num_updates = 0;
        _latest_message = "Update Number \"";
        _latest_message += std::to_string(++num_updates);
        _latest_message += "\" Processed!";
        Notify();
    }

    // TODO: Add some cleanup steps, no duplicateso

private:
    // important that all subscribers / observers use the same interface.
    std::list<SubscriberInterface*> _subs;
    std::string _latest_message = "default message";
};

// THE POINT:
// The observer pattern can get as complex as you want, 
// to simplify some of the things down, once you have a lot of things going on
// but you want other things to know about it too, without having direct access to the whole class

// Can be done with Composition pattern as well, the 'pimple' idiom.
// Instead of base concrete class, 'Subject', you would instead, 
// you would have the subject class already pre-defined, and then just add it.
// Below the 'Subject' class, we would have another class that doesn't inherit from 'Subject'
// but has a private member 'Subject' ptr.  Instiate the subject member on construction. 
// But, you would need to forward all the main functions from Subject. 
// Then, to add, we would use the private subject, which would add an observer to _subs
// list of the Subject class indirectly.