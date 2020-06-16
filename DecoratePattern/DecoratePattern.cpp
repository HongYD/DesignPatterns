// DecoratePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"Beverage.h"
int main()
{
    Beverage* pBeverage = new Espresso();
    cout << pBeverage->GetDescription() << " $" << pBeverage->cost() << endl;

    Beverage* pBeverage2 = new Espresso();
    pBeverage2 = new Mocha(pBeverage2);
    pBeverage2 = new Mocha(pBeverage2);
    cout << pBeverage2->GetDescription() << " $" << pBeverage2->cost() << endl;

    pBeverage2 = new Whip(pBeverage2);
    cout << pBeverage2->GetDescription() << " $" << pBeverage2->cost() << endl;

    return 0;
}

