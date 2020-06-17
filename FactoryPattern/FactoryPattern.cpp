// FactoryPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include"Pizza.h"
#include"PizzaStore.h"
using namespace std;
int main()
{
    PizzaStore* nypizzastore = new NYPizzaStore();
    PizzaStore* chikagostore = new ChicagoPizzaStore();

    Pizza* pz1= nypizzastore->orderPizza(PizzaType::Cheese);
    cout << "I ordered " << pz1->getName() << " pizza" << endl;

    Pizza* pz2 = chikagostore->orderPizza(PizzaType::Pepperoni);
    cout << "I ordered " << pz2->getName() << " pizza" << endl;
}

