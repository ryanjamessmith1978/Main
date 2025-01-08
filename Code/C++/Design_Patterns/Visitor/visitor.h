// Visitor pattern is a behavioral pattern decouples functionality from your components.
#include <string>
#include <iostream>

class ComponentA;
class ComponentB;
class ComponentC;

// things to operate on, visitor needs to know about them.
// This is the visitor class to apply pattern.
class Visitor { 
public:
    // these will called something more in the line of what they do.  
    // they are const because they aren't going to change anything, they are only going to visit things and run functions.
    // only public
    // Visitor interface needs to define public functions passing the type of components it has access to.  
    virtual void VisitComponentA(const ComponentA* comp) const = 0;
    virtual void VisitComponentB(const ComponentB* comp) const = 0;
    virtual void VisitComponentC(const ComponentC* comp) const = 0;
};

// Base component class that's an interface
class Component {
public:
    virtual ~Component() {}
    // accept a visitor ptr.  Needs to be pointer because the visitor is a pure virtual class.
    virtual void Accept(Visitor* visitor) const = 0; 
};

// Note: the point is, we add functionality to the visitors instead of the components.
// Components call functions that pass in the visitor which in turn calls visitor functions that pass in itself
// giving the visitor access to the component to perform behaviors on them.
// And, thanks to polymorphism the component function that passes in the visitor pointer doesn't have to
// specify which concrete visitor class it is.  
// 
// All kinds of visitors that do special things, publicly.
// Don't need to edit components, hence the visitor pattern.e
class ComponentA : public Component {
public:
    virtual void Accept(Visitor* visitor) const override {
        visitor->VisitComponentA(this); // passes this component to the visitor.
    }
    // the visitor now has access to these component functions.  
    std::string ComponentAFunc() const {
        return "ComponentA";
    }
};

class ComponentB : public Component {
public:
    virtual void Accept(Visitor* visitor) const override {
        visitor->VisitComponentB(this);
    }
    std::string ComponentBFunc() const {
        return "ComponentB";
    }
};

class ComponentC : public Component {
public:
    virtual void Accept(Visitor* visitor) const override {
        visitor->VisitComponentC(this);
    }
    std::string ComponentCFunc() const {
        return "ComponentC";
    }
};

// Visitor concrete classes would have specific functionality and would be called something
// analogous to what that functionality is.  Instead of 'Visitor1' it would be 'VisitorPrint' for example.
#include <iostream>
class Visitor1 : public Visitor {
public:
    void VisitComponentA(const ComponentA* comp) const {
        std::cout << "visited" << comp->ComponentAFunc() << "from Visitor1\n";
    }
    void VisitComponentB(const ComponentB* comp) const {
        std::cout << "visited" << comp->ComponentBFunc() << "from Visitor1\n";
    }
    void VisitComponentC(const ComponentC* comp) const {
        std::cout << "visited" << comp->ComponentCFunc() << "from Visitor1\n";
    }
};

class Visitor2 : public Visitor {
public:
    void VisitComponentA(const ComponentA* comp) const {
        std::cout << "visited" << comp->ComponentAFunc() << "from Visitor2\n";
    }
    void VisitComponentB(const ComponentB* comp) const {
        std::cout << "visited" << comp->ComponentBFunc() << "from Visitor2\n";
    }
    void VisitComponentC(const ComponentC* comp) const {
        std::cout << "visited" << comp->ComponentCFunc() << "from Visitor2\n";
    }
};