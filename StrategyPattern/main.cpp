// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"Duck.h"
#include"Strategy.h"

int main()
{
    Duck* mallard = new MallardDuck();
    mallard->display();
    mallard->performFly();
    mallard->performQuack();
    mallard->swim();
    std::cout << std::endl;

    Duck* model = new ModelDuck();
    model->performFly();
    model->performQuack();
    model->swim();
    model->setFlyPerform(new FlyWithRocket());
    model->performFly();

    Strategy* s = new ConcreteStrategyA();
    Context* c = new Context(s);
    c->ContextInterface();  // ConcreteStrategyA
    delete s;
    delete c;
    return 0;

}

