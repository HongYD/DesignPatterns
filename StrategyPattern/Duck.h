#pragma once
#include<iostream>
class FlyBehavior {
public:
	virtual void Fly();
};

class FlyWithWings :public FlyBehavior {
	void Fly() {
		std::cout << "I am flying with wings" << std::endl;
	}
};
class FlyNoWay :public FlyBehavior {
	void Fly() {
		std::cout << "I can't fly" << std::endl;
	}
};
class FlyWithRocket :public FlyBehavior {
	void Fly() {
		std::cout << "I am flying with rockets" << std::endl;
	}
};

class QuackBehavior {
public:
	virtual void Quack();
};

class QuackNormal :public QuackBehavior {
	void Quack()
	{
		std::cout << "Quack!!!" << std::endl;
	}
};

class QuackSilence :public QuackBehavior {
	void Quack()
	{
		std::cout << "Silence" << std::endl;
	}
};

class Squeak :public QuackBehavior {
	void Quqck() {
		std::cout << "Squeak" << std::endl;
	}
};

class Duck
{
public:
	FlyBehavior* flybehavior;
	QuackBehavior* quackbehavior;

	void performQuack();
	void performFly();
	void swim();
	void setQuackPerform(QuackBehavior* quackbehav);
	void setFlyPerform(FlyBehavior* flybehav);
	virtual void display()=0;

};

class MallardDuck :public Duck {
public:
	MallardDuck() {
		quackbehavior = new QuackNormal();
		flybehavior = new FlyWithWings();
	}
	
	void display() {
		std::cout << "I am real  Mallard Duck" << std::endl;
	}
};

class ModelDuck :public Duck {
public:
	ModelDuck() {
		quackbehavior = new QuackSilence();
		flybehavior = new FlyNoWay();
	}

	void display() {
		std::cout << "I am real  Model Duck" << std::endl;
	}
};

