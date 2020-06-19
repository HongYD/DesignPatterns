// CommandPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"Receiver.h"

int main()
{
    Command* c = new ConcreteCommand();
    Receiver* r = new Receiver();
    c->setReceiver(r);

    Invoker i;
    i.setCommand(c);
    i.Notify();

    delete r;
    delete c;

    return 0;

}


