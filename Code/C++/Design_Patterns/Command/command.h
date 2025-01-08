// Command.h | Base definitions of what a command is.

#include <string>
#include <iostream>

// COMMAND INTERFACE: Build commands and use polymorphism to process variety of commands
class ICommand {
public:
    virtual ~ICommand() {}
    virtual void Execute() const = 0;
};


// example of a simple command
class LogCommand : public ICommand {
public:
    // don't allow to construct in any other way, need to pass in command
    LogCommand(std::string data) : pay_load_(data) {} 

    void Execute() const override {
        std::cout << "printstring: " << pay_load_ << '\n'; // Simple because no separate receiver class
    }

    // create a logger command,
    // different function to choose where to log to // TODO:

private:
    std::string pay_load_;
public:

    LogCommand() = delete;
};

// A class in your code that handles your main logic.
// Delegation Pattern crossover, command comes in, then command gets delegated to Receiver
// You could create a Reciever interface, have multiple receivers, and change receivers on the fly.
class Reciever {
public:
    void ProcessA(const std::string& proc_a_stuff) {
        std::cout << "Reciever(ProcessA) is working on: " << proc_a_stuff << '\n';
    }
    void ProcessB(const std::string& proc_b_stuff) {
        std::cout << "Reciever(ProcessB) is working on: " << proc_b_stuff << '\n';
    }
    //... todo: more business logic
};

class ComplexCommand : public ICommand {
public:
    ComplexCommand(Reciever* receiver, std::string a, std::string b)
        : reciever_(receiver), proc_a_details(a), proc_b_details(b)
    {}

    // 'this->' prevents confusion with multiple inheritance.
    void Execute() const override {
        this->reciever_->ProcessA(proc_a_details); // keep logic on the commands as simple as possible.
        this->reciever_->ProcessB(proc_b_details); // all logic should be checked and handled by receiver.
    }

private: 
    // If it were it's own object (instead of a ptr), Reciever receiver, would be instantiated here, 
    // we'd have a copy of the business logic inside every command.
    Reciever* reciever_;  // not owned- probably should be refactored to a shared ptr
    std::string proc_a_details;
    std::string proc_b_details;
};

class Invoker {
public:

    // Invoker typically handles your main loop.
    // Passes commands off to Receivers.
    ~Invoker() {
       // delete on_startup_command;
       // delete on_mid_command;
       // delete on_shutdown;
    }

    void SetStartupCommand(ICommand* command) {
        on_startup_command = command; // better method to use pointers than copying them like this. needs optimized.
    }
    void SetMidCommand(ICommand* command) {
        on_mid_command = command; 
    }
    void SetShutdownCommand(ICommand* command) {
        on_shutdown = command;
    }

    void DoTheWork() {
        if (on_startup_command) {
            on_startup_command->Execute();
        }
        if (on_mid_command) {
            on_mid_command->Execute();
        }
        if (on_shutdown) {
            on_shutdown->Execute();
        }
    }

private:
    ICommand* on_startup_command = nullptr; 
    ICommand* on_mid_command = nullptr;
    ICommand* on_shutdown = nullptr;
};