// Chain.h | Chain of Command Pattern
// Handler interface will work with event structs.
// In a chain of command, you got to be something with a request (hence handler interface and struct event).
// Build a concrete set of handlers that implements the IHandler interface, including a base parent handler.

#pragma once
#include <string>
#include <iostream>

struct Event {
    int id = -1; 
    std::string message = "";
};

// Interface Handler to handle events
// base option for a way to add to the chain of responsibility

class IHandler { 
public:
    virtual ~IHandler() {}
    virtual IHandler* SetNext(IHandler* handler) = 0;
    virtual Event Handle(Event event) = 0;
};

// Concrete class that acts as the main parent for the handlers.
class BaseHandler : public IHandler {
public:
    BaseHandler() : next_handler(nullptr) {}

    IHandler* SetNext(IHandler* handler) override 
    {
        next_handler = handler;
        return handler; // setting next handler and returning handler allows us to chain handlers.
    }

    // event == request, often those two variable names are interchangeable.
    // base case, if no specialized event handled, this will get called.
    Event Handle(Event event) override 
    {
        if (next_handler) {
            return next_handler->Handle(event); 
        } // the next_handler is a member variable that will change each time it goes through the chain of responsibility

        return event; // if it falls through, it will instantiate a new event
    }

private:
    IHandler* next_handler; // this is unique for each child class if setNext is run for each handler you want to chain.
};

class HandleEvent1 : public BaseHandler {
public:
    Event Handle(Event event) override 
    {
        if (event.id == 1) 
        {
            std::cout << "-> handling event with id 1\n";
            std::cout << "   event message: " << event.message << std::endl;
            return event;
        }

        return BaseHandler::Handle(event); // falls through to base class event handle call, which returns an event.
    }
};

class HandleEvent2 : public BaseHandler {
public:
    Event Handle(Event event) override {
        if (event.id == 2) {
            std::cout << "-> handling event with id 2\n";
            std::cout << "   event message: " << event.message << std::endl;
            return event;
        }
        return BaseHandler::Handle(event);
    }
};

class HandleEvent3 : public BaseHandler {
public:
    Event Handle(Event event) override {
        if (event.id == 3) {
            std::cout << "-> handling event with id 3\n";
            std::cout << "   event message: " << event.message << std::endl;
            return event;
        }
        return BaseHandler::Handle(event);
    }
};
