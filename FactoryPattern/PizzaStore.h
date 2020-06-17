#pragma once
#include<iostream>
#include<string>
#include"Pizza.h"
using namespace std;

class PizzaStore
{
public:
	
	Pizza* orderPizza(PizzaType style) {
		Pizza* pizza;
		pizza = createPizza(style);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	}
protected:
	virtual Pizza* createPizza(PizzaType type)=0;
};

class NYPizzaStore :public PizzaStore {
	Pizza* createPizza(PizzaType item) {
		if (item == PizzaType::Cheese) {
			return new NYStyleCheesePizza();
		}
		else if (item == PizzaType::Clam) {
			return new NYStyleClamPizza();
		}
		else if (item == PizzaType::Veggie) {
			return new NYStyleVeggiePizza();
		}
		else if (item == PizzaType::Pepperoni) {
			return new NYStylePepperonPizza();
		}
		else {
			return NULL;
		}
	}
};

class ChicagoPizzaStore :public PizzaStore {
	Pizza* createPizza(PizzaType item) {
		if (item == PizzaType::Cheese) {
			return new ChicagoStyleCheesePizza();
		}
		else if (item == PizzaType::Clam) {
			return new ChicagoStyleClamPizza();
		}
		else if (item == PizzaType::Veggie) {
			return new ChicagoStyleVeggiePizza();
		}
		else if (item == PizzaType::Pepperoni) {
			return new ChicagoStylePepperonPizza();
		}
		else {
			return NULL;
		}
	}
};