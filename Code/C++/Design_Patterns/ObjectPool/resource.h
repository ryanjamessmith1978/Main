#include <cstdlib>

// Resource is just an integer for illustration purposes.
class Resource {
private:
    int value;
public:
    Resource() {
        value = 0;
    }
    void reset() {
        value = 0;
    }
    int getValue() {
        return value;
    }
    void setValue(int number) {
        value = number;
    }
};