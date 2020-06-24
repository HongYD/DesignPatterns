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
/// װ���߼̳���Ҳ���Գ���Beverage��
/// </summary>
class CondimentDecorator :public Beverage {
public:
	string getDescription() { return ""; }
};


/// <summary>
/// ��װ���ߣ�ֱ�Ӽ̳��Գ��� Beverage
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
/// װ���ߣ���Ӽ̳���Beverage
/// </summary>
class Mocha :public CondimentDecorator {
private:
	//װ������һ�����������
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

