// Chain_Of_Responsibility.cpp | https://www.youtube.com/watch?v=yXJHXDy5oig
// Chain Of Command Pattern
// 

#include "chain.h"

int main() {
    HandleEvent1* handleevent1 = new HandleEvent1;
    HandleEvent2* handleevent2 = new HandleEvent2;
    HandleEvent3* handleevent3 = new HandleEvent3;
    
    // this first part returns handlerevent2, so you can go right into ->SetNext(handlerevent3)
    handleevent1->SetNext(handleevent2)->SetNext(handleevent3); // this sets the chain of responsibility.
    
    // handleevent1->SetNext(handleevent2); // or you could do it on separate lines. 
    // handleevent2->SetNext(handleevent3);
    Event an_event;
    an_event.id = 3;
    an_event.message = "ID 3 being handle by HandleEvent1 handler class! \n\n";

    handleevent1->Handle(an_event);

    /*{
        std::cout << "TEST1\n";
        Event an_event;
        an_event.id = 1;
        an_event.message = "why hello there from TEST1";
        Event returned_event = handleevent1->Handle(an_event);
        std::cout << "returned event id: " << returned_event.id << std::endl;
    }

    {
        std::cout << "TEST2\n";
        Event an_event;
        an_event.id = 2;
        an_event.message = "why hello there from TEST2";
        Event returned_event = handleevent1->Handle(an_event);
        std::cout << "returned event id: " << returned_event.id << std::endl;
    }

    {
        std::cout << "TEST3\n";
        Event an_event;
        an_event.id = 3;
        an_event.message = "why hello there from TEST3";
        Event returned_event = handleevent1->Handle(an_event);
        std::cout << "returned event id: " << returned_event.id << std::endl;
    }

    {
        std::cout << "TEST4\n";
        Event an_event;
        an_event.id = 4;
        an_event.message = "why hello there from TEST4";
        Event returned_event = handleevent1->Handle(an_event);
        std::cout << "returned event id: " << returned_event.id << std::endl;
    }*/

    system("pause");
}

// CHAIN OF COMMAND
// Build commands or requests and hand them off appropriately.
// Chain of processing.  Design varies of what you're chaining
// This is a good generic way to handle requests that a variety of options they do.