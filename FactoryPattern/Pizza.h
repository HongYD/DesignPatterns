#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum PizzaType
{
	Cheese,
	Veggie,
	Clam,
	Pepperoni
};

class Pizza
{
public:
	string name;
	string dough;
	string sauce;
	vector<string>toppings;

	void prepare() {
		cout << "Prepare: " << name << endl;
		cout << "Tossing dough..." << endl;
		cout << "Adding sauce..." << endl;
		cout << "Adding toppings: " << endl;
		for (int i = 0; i < toppings.size(); i++) {
			cout << "  " << toppings.at(i) << " ";			
		}
		cout << endl;
	}
	void bake() {
		cout << "Bake for 25 minutes at 35" << endl;
	}

	virtual void cut() {
		cout << "Cutting the Pizza into disgonal slices" << endl;
	}

	void box() {
		cout << "Place pizza in offical PizzaStore box" << endl;
	}

	string getName() {
		return name;
	}
};

#pragma region NYstyle Pizza
class NYStyleCheesePizza :public Pizza {
public:
	NYStyleCheesePizza() {
		name = "NY Style Sauce and Cheese Pizza";
		dough = "Thin Crust Dough";
		sauce = "Marinara Sauce";
		toppings.push_back("Grate Reggiano Cheese");
	}
};

class NYStyleVeggiePizza :public Pizza {
public:
	NYStyleVeggiePizza() {
		name = "NY Style Sauce and Veggie Pizza";
		dough = "Thin Crust Dough";
		sauce = "Veggie Sauce";
		toppings.push_back("Grate Veggie");
	}
};

class NYStyleClamPizza :public Pizza {
public:
	NYStyleClamPizza() {
		name = "NY Style Sauce and Clam Pizza";
		dough = "Thin Crust Dough";
		sauce = "Clam Sauce";
		toppings.push_back("Grate Clam");
	}
};

class NYStylePepperonPizza :public Pizza {
public:
	NYStylePepperonPizza() {
		name = "NY Style Sauce and Pepperon Pizza";
		dough = "Thin Crust Dough";
		sauce = "Pepperon Sauce";
		toppings.push_back("Grate Pepperon Cheese");
	}
};
#pragma endregion


#pragma region ChicagoStylePizza
class ChicagoStyleCheesePizza :public Pizza {
public:
	ChicagoStyleCheesePizza() {
		name = "Chicago Style Deep Dish Cheese Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";

		toppings.push_back("Shredded Mozzzarella Cheese");
	}

	void cut() {
		cout << "Cutting the Pizza into square slices" << endl;
	}
};

class ChicagoStyleVeggiePizza :public Pizza {
public:
	ChicagoStyleVeggiePizza() {
		name = "Chicago Style Veggie Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Veggie Sauce";

		toppings.push_back("Veggie");
	}

	void cut() {
		cout << "Cutting the Pizza into square slices" << endl;
	}
};

class ChicagoStyleClamPizza :public Pizza {
public:
	ChicagoStyleClamPizza() {
		name = "Chicago Style Clam Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Clam Sauce";

		toppings.push_back("Clam");
	}

	void cut() {
		cout << "Cutting the Pizza into square slices"<<endl;
	}
};

class ChicagoStylePepperonPizza :public Pizza {
public:
	ChicagoStylePepperonPizza() {
		name = "Chicago Style Pepperon Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Pepperon Sauce";

		toppings.push_back("Pepperon");
	}

	void cut() {
		cout << "Cutting the Pizza into square slices" << endl;
	}
};
#pragma endregion



