#pragma once
#include<iostream>
using namespace std;
class Strategy
{
public:
	virtual void AlgorithmInterface() = 0;
	virtual ~Strategy(){}
};

class ConcreteStrategyA :public Strategy {
public:
	void AlgorithmInterface() {
		cout << "ConcreteStrategyA" << endl;
	}
};

class ConcreteStrategyB :public Strategy {
public:
	void AlgorithmInterface() {
		cout << "ConcreteStrategyB" << endl;
	}
};

class Context {
private:
	Strategy* strategy;
public:
	Context(Strategy* s) {
		strategy = s;
	}
	void ContextInterface() {
		strategy->AlgorithmInterface();
	}
};
