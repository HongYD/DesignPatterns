#pragma once
#include<iostream>
class SoldOutState;
class NoQuarterState;
class HasQuarterState;
class SoldState;
class GumballMachine;
using namespace std;

/// <summary>
/// 抽象状态接口
/// </summary>
class State
{
public:
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;
};

/// <summary>
/// 上下文
/// </summary>


class GumbalMachine {
public:
	State* soldOutState;
	State* noQuaterState;
	State* hasQuarterState;
	State* soldState;

	State* state = soldOutState;

	int count = 0;
public:
	GumbalMachine(int numberGumballs) {
		this->soldOutState = new SoldOutState(this);
		noQuaterState = new NoQuarterState(this);
		hasQuarterState = new HasQuarterState(this);
		soldState = new SoldState(this);
		this->count = numberGumballs;
		if (numberGumballs > 0) {
			state = noQuaterState;
		}
	}

	void insertQuarter() {
		state->insertQuarter();
	}

	void ejectQuater() {
		state->ejectQuarter();
	}

	void turnCrank() {
		state->turnCrank();
	}

	void setState(State* state) {
		this->state = state;
	}

	void releaseBall() {
		cout << "A gumball comes rolling out the slot..." << endl;
		if (count != 0) {
			count = count - 1;
		}
	}

	State* getSoldOutState() {
		return this->soldOutState;
	}

	State* getNoQuarterState() {
		return this->noQuaterState;
	}

	State* getHasQuarterState() {
		return this->hasQuarterState;
	}

	State* getSoldState() {
		return this->soldOutState;
	}

	int getCount() {
		return this->count;
	}
};

/// <summary>
/// 具体状态，存放一个对于上下文的反向引用
/// </summary>
class NoQuarterState :public State {
	GumbalMachine* gumbalMachine;
public:
	NoQuarterState(GumbalMachine* _gbm) {
		this->gumbalMachine = _gbm;
	}

	void insertQuarter() {
		cout << "You insert a quarter!" << endl;
		gumbalMachine->setState(gumbalMachine->getNoQuarterState());
	}

	void ejectQuarter() {
		cout << "You haven't insert a quarter!" << endl;
	}

	void turnCrank() {
		cout << "You turned,but there's no quarter" << endl;
	}

	void dispense() {
		cout << "You need to pay first" << endl;
	}
};

class HasQuarterState :public State {
	GumbalMachine* gumbalMachine;
public:
	HasQuarterState(GumbalMachine* _gbm) {
		this->gumbalMachine = _gbm;
	}

	void insertQuarter() {
		cout << "You can't insert another quarter!" << endl;
	}

	void ejectQuarter() {
		cout << "quarter returned" << endl;
		gumbalMachine->setState(gumbalMachine->getNoQuarterState());
	}

	void turnCrank() {
		gumbalMachine->setState(gumbalMachine->getSoldState());
	}

	void dispense() {
		cout << "No gumball dispense" << endl;
	}
};

class SoldState :public State {
	GumbalMachine* gumbalMachine;
public:
	SoldState(GumbalMachine* _gbm) {
		this->gumbalMachine = _gbm;
	}

	void insertQuarter() {
		cout << "Please wait, we're already giving you a gumball!" << endl;
	}

	void ejectQuarter() {
		cout << "Sorry,you already turned thr crank" << endl;
	}

	void turnCrank() {
		cout << "Turning twice doesn't get you another gumball" << endl;
	}

	void dispense() {
		gumbalMachine->releaseBall();
		if (gumbalMachine->getCount() > 0) {
			gumbalMachine->setState(gumbalMachine->getHasQuarterState());
		}
		else {
			gumbalMachine->setState(gumbalMachine->getSoldOutState());
		}
	}
};

class SoldOutState :public State {
	GumbalMachine* gumbalMachine;
public:
	SoldOutState(GumbalMachine* _gbm) {
		this->gumbalMachine = _gbm;
	}

	void insertQuarter() {
		cout << "Don't insert, we sold out!" << endl;

	}

	void ejectQuarter() {
		cout << "No gumball anymore!" << endl;
	}

	void turnCrank() {
		cout << "No gumball anymore!" << endl;
	}

	void dispense() {
		cout << "No gumball dispense!" << endl;
	}
};





