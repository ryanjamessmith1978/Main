// Interpreter.cpp | https://sourcemaking.com/design_patterns/interpreter/cpp/1

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

class Thousand;
class Hundred;
class Ten;
class One;

class RNInterpreter
{
public:
    RNInterpreter(); // ctor for client
    RNInterpreter(int) {}
    // ctor for subclasses, avoids infinite loop
    int interpret(const char*); // interpret() for client
    virtual void interpret(const char* input, int& total)
    {
        // for internal use
        int index;
        index = 0;
        if (!strncmp(input, nine(), 2))
        {
            total += 9 * multiplier();
            index += 2;
        }
        else if (!strncmp(input, four(), 2))
        {
            total += 4 * multiplier();
            index += 2;
        }
        else
        {
            if (input[0] == five())
            {
                total += 5 * multiplier();
                index = 1;
            }
            else
                index = 0;
            for (int end = index + 3; index < end; index++)
                if (input[index] == one())
                    total += 1 * multiplier();
                else
                    break;
        }

        char* myString = (char*)input;
        //strcpy_s((char*)input, sizeof(input), input[index]);
        int r = strcpy_s(myString, sizeof(input), (const char*)input[index]);

    } // remove leading chars processed

protected:
    // cannot be pure virtual because client asks for instance
    virtual char one() { return ' '; }
    virtual const const char* four() { return nullptr; }
    virtual char five() { return ' '; }
    virtual const char* nine() { return nullptr; }
    virtual int multiplier() { return 0; }

private:
    RNInterpreter* thousands;
    RNInterpreter* hundreds;
    RNInterpreter* tens;
    RNInterpreter* ones;
};

class Thousand : public RNInterpreter
{
public:
    // provide 1-arg ctor to avoid infinite loop in base class ctor
    Thousand(int) : RNInterpreter(1) {}

protected:
    char one()
    {
        return 'M';
    }
    const const char* four()
    {
        return nullptr;
    }
    char five()
    {
        return '\0';
    }
    const char* nine()
    {
        return nullptr;
    }
    int multiplier()
    {
        return 1000;
    }
};

class Hundred : public RNInterpreter
{
public:
    Hundred(int) : RNInterpreter(1) {}

protected:
    char one()
    {
        return 'C';
    }
    const const char* four()
    {
        return "CD";
    }
    char five()
    {
        return 'D';
    }
    const const char* nine()
    {
        return "CM";
    }
    int multiplier()
    {
        return 100;
    }
};

class Ten : public RNInterpreter
{
public:
    Ten(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'X';
    }
    const const char* four()
    {
        return "XL";
    }
    char five()
    {
        return 'L';
    }
    const char* nine()
    {
        return "XC";
    }
    int multiplier()
    {
        return 10;
    }
};

class One : public RNInterpreter
{
public:
    One(int) : RNInterpreter(1) {}
protected:
    char one()
    {
        return 'I';
    }
    const const char* four()
    {
        return "IV";
    }
    char five()
    {
        return 'V';
    }
    const char* nine()
    {
        return "IX";
    }
    int multiplier()
    {
        return 1;
    }
};

RNInterpreter::RNInterpreter()
{
    // use 1-arg ctor to avoid infinite loop
    thousands = new Thousand(1);
    hundreds = new Hundred(1);
    tens = new Ten(1);
    ones = new One(1);
}

int RNInterpreter::interpret(const char* input)
{
    int total;
    total = 0;
    thousands->interpret(input, total);
    hundreds->interpret(input, total);
    tens->interpret(input, total);
    ones->interpret(input, total);
    if (strcmp(input, ""))
        // if input was invalid, return 0
        return 0;
    return total;
}

int main()
{
    RNInterpreter interpreter;
    char input[20];
    std::cout << "Enter Roman Numeral: ";
    while (std::cin >> input)
    {
        std::cout << "   interpretation is " << interpreter.interpret(input) << std::endl;
        std::cout << "Enter Roman Numeral: ";
    }
}