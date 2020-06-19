#pragma once
#include<iostream>
#include<list>
using namespace std;
class Receiver
{
public:
	void Action() {
		cout << "Receiver" << endl;
	}
};

class Command {
public:
	virtual void Excute() = 0;
	virtual void setReceiver(Receiver* r) = 0;
	virtual ~Command() {};
};

class ConcreteCommand :public Command {
private:
	Receiver* receiver;
public:
	void setReceiver(Receiver* r) {
		receiver = r;
	}

	void Excute() {
		receiver->Action();
	}
};

class Invoker {
private:
	list<Command*>commands;
public:
	void setCommand(Command* c) {
		commands.push_back(c);
	}
	void Notify() {
		for (auto c = commands.begin(); c != commands.end(); c++) {
			(*c)->Excute();
		}
	}
};


