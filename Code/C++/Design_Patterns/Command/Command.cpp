// Command.cpp | https://www.youtube.com/watch?v=yDkIK3JfHkw&list=PLalVdRk2RC6otl3oBU2cn-P6DWi1y1PS3&index=14


#include "command.h"

int main() {

	// simple command demo
	LogCommand lc("this is my message to log");
	lc.Execute();

	//complex command demo
	Reciever rec;
	ComplexCommand cc(&rec, "string a", "string b");
	cc.Execute();

	// ^^ Above are simple examples of how commands work directly in main individually, but not used in practice.
	// Typically, you have an Invoker which wraps all your core business logic.
	// Invoker handles a bunch of different commands.  Allows you to batch together commands.

	// invoking sets of commands demo
	Invoker invoker; 
	//invoker.SetStartupCommand(new LogCommand("starting up"));
	//invoker.SetMidCommand(&cc);
	//invoker.SetShutdownCommand(new LogCommand("shutting down"));

	//invoker.DoTheWork();
	system("pause");
}

// COMMAND PATTERN
// Any object you create to do something or pass to something else to do something.
// Difference between an Invoker and a Receiver?