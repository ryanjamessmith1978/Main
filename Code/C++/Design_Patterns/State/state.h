#pragma once
#include <iostream>
#include <typeinfo>
#define classname typeid(this).name()

//  State Pattern - Base state - abstract class (at least one virtual member function).
// States do some sort of work.  Behavioral pattern.
// The State's class it's interacting with (like the main game loop) will have a pointer to that class,
// and that class will have a pointer to the state.  
// During the State's partner class's (Engine) constructor is called, it runs a Transition to which takes in a state,
// the newly constructed Engine sets a member ptr to current state, and has the state call it's set engine. So, they both
// have pointers to each other.

class Engine;

class State {
protected:
    Engine* _engine; // not owned by the state, not going to ever delete it, in case we want to change state.

public:
    virtual ~State() {}

    // From the state, we want to call set_engine, so that, it has a back reference to the engine.
    // 
    // Because : when we run DoWorkA() or DoWorkB() later, sometimes they'll have a transition, 
    // that way, we'll be able to reference the engine, and call TransitionTo() to setup other States!
    void set_engine(Engine* engine) {
        _engine = engine; // method that's called in Engine transitionTo States function.  After engine changes to a different state, it sets a reference back to engine. 
    }

    virtual void DoWorkA() = 0;
    virtual void DoWorkB() = 0;
};

class Engine {
private:
    State* _state;

public:
    Engine(State* state) : _state(nullptr) {
        TransitionTo(state);
    }

    ~Engine() { delete _state; } // Engine has ownership of the states.  

    void TransitionTo(State* state) {
        if (_state) delete _state;
        _state = state;
        _state->set_engine(this);
    }

    // Engine delegates some of it's function to the states here!
    void RequestA() { _state->DoWorkA(); }
    void RequestB() { _state->DoWorkB(); }
};

class ConcreteStateA : public State {
public:
    void DoWorkA() override {
        std::cout << classname << " called DoWorkA()\n"; } 
    
    void DoWorkB() override {
        std::cout << classname << " called DoWorkB()\n";
    }
};

class ConcreteStateB : public State {
public:
    void DoWorkA() override {
        std::cout << classname << " called DoWorkA()\n"; // change the context, ConcreteState B class DoWorkA(),
        _engine->TransitionTo(new ConcreteStateA);      // transition to ConcreteState A, 
    }                                                   // states have protected member, engine pointer (defined in abstract base).
    void DoWorkB() override {                           // flip all the states around that you need.

        std::cout << classname << " called DoWorkB()\n";
    }
};
