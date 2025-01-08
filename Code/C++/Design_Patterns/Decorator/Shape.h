#include <iostream>
#include <string>

// pure virtual, interface
struct Shape {
    virtual ~Shape() = default;

    virtual std::string GetName() const = 0; // pure virtual | interface | cannot instantiate directly
};

struct Circle : Shape {

    void Resize(float factor) { radius *= factor; }

    std::string GetName() const override {
        return std::string("A circle of radius ") + std::to_string(radius);
    }

    // Properties
    float radius = 10.0f;
};

struct ColoredShape : Shape 
{
    ColoredShape(const std::string& color, Shape* shape)
        : color(color), shape(shape) {}

    std::string GetName() const override {
        return shape->GetName() + " which is colored " + color;
    }

   
    std::string color;
    Shape* shape; // pointer allows this to be a flyweight.  pass in the same pointer, whatever one you are filling out here, and you are filling out circle over and over
    // reuse circle over and over, and you want it to the be same.
    // However, modifying one pointer value, will modify all of the circles.

    // would need to cast *shape to a circle to Resize a coloredShape.
};