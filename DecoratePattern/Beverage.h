#pragma once
#include<iostream>
#include<string>
using namespace std;
class Beverage
{
private:
	string description;
public:
	Beverage(string str="Unknow Beverage"):description(str){}
	virtual string GetDescription() {
		return description;
	};
	virtual double cost() { return 0; }
};

/// <summary>
/// 装饰者继承自也来自超类Beverage类
/// </summary>
class CondimentDecorator :public Beverage {
public:
	string getDescription() { return ""; }
};


/// <summary>
/// 被装饰者，直接继承自超类 Beverage
/// </summary>
class Espresso :public Beverage {
public:
	Espresso() :Beverage("Espresso") {}
	double cost() {
		return 1.99;
	}
};

class HouseBlend : public Beverage
{
public:
	HouseBlend() :Beverage("HouseBlend Coffee") {}

	double cost()
	{
		return 0.89;
	}
};

/// <summary>
/// 装饰者，间接继承至Beverage
/// </summary>
class Mocha :public CondimentDecorator {
private:
	//装饰者有一个超类的引用
	Beverage* beverage;
public:
	Mocha(Beverage* beve) {
		beverage = beve;
	}
	string getDescription() {
		return beverage->GetDescription() + ", Mocha";
	}
	double cost() {
		return 0.20 + beverage->cost();
	}
};

class Whip :public CondimentDecorator {
private:
	Beverage* beverage;
public:
	Whip(Beverage* beve) {
		beverage = beve;
	}
	string getDescription()
	{
		return beverage->GetDescription() + ", Whip";
	}
	double cost() {
		return 0.15 + beverage->cost();
	}
};

