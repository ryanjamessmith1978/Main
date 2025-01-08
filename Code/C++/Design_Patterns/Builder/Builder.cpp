// Builder.cpp |  https://www.youtube.com/watch?v=D1CnNAszv_M&list=PLk6CEY9XxSIDZhQURp6d8Sgp-A0yKKDKV&index=7
// 
// Question: WHY Builder Design Pattern?
// Because i want to build an object (e.g. plane) that is composed of complex subomponents (e.g. body, engine) 
// Because i want to create complex objects step-by-step
//
// Builder Pattern has a 'Director' object
// Director object tells all the builders how they will build the object.

#include <iostream>
using namespace std;

// Your end product - after builder finishes, it returns the whole plane.
class Plane {
    string _plane; // plane type name, not parent object or separate object.
    string _body;
    string _engine;
public:
    Plane(string planeType) :_plane{ planeType } {}
    void setEngine(string type) { _engine = type; }
    void setBody(string body) { _body = body; }
    string getEngine() { return _engine; }
    string getBody() { return _body; }

    void show() {
        cout << "Plane Type: " << _plane << endl
            << "Body Type: " << _body << endl
            << "Engine Type: " << _engine << endl << endl;
    }
};

// PlaneBuilder Abstract Class
// Means all builders should have atleast these methods
class PlaneBuilder {
public:
    virtual void getPartsDone() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    //virtual ~PlaneBuilder(){}
    Plane* getPlane() { return _plane; }

protected:
    Plane* _plane;
};

// PlaneBuilder concrete class
// knows only how to build Propeller Plane
class PropellerBuilder : public PlaneBuilder {
public:
    void getPartsDone() { _plane = new Plane("Propeller Plane"); }
    void buildEngine() { _plane->setEngine("Propeller Engine"); }
    void buildBody() { _plane->setBody("Propeller Body"); }
    //~PropellerBuilder(){delete _plane;}
};

// PlaneBuilder concrete class
// Knows only how to build Jet Plane
class JetBuilder : public PlaneBuilder {
public:
    void getPartsDone() { _plane = new Plane("Jet Plane"); }
    void buildEngine() { _plane->setEngine("Jet Engine"); }
    void buildBody() { _plane->setBody("Jet Body"); }
    //~JetBuilder(){delete _plane;}
};

// Defines steps and tells to the builder that build in given order.
class Director{    
public:
    // different builders can be passed in that create different planes
    Plane* createPlane(PlaneBuilder* builder) { // plane needs to be constructed in this specific order.
        builder->getPartsDone(); // Step 1
        builder->buildBody(); // Step 2
        builder->buildEngine(); // Step 3
        return builder->getPlane(); // Step 4
    }

private:
    PlaneBuilder* builder;
};

int main() {

    Director dir;
    JetBuilder jb;
    PropellerBuilder pb;

    Plane* jet = dir.createPlane(&jb);
    Plane* pro = dir.createPlane(&pb);

    jet->show();
    pro->show();

    delete jet;
    delete pro;

    system("pause");

    return 0;
}

// *** BUILDER DESIGN PATTERN NOTES ***
// 
//
//