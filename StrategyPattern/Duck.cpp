#include "Duck.h"

void Duck::performQuack()
{
	quackbehavior->Quack();
}

void Duck::performFly()
{
	flybehavior->Fly();
}

void Duck::swim()
{
	std::cout << "I am swimmig" << std::endl;
}

void Duck::setQuackPerform(QuackBehavior* quackbehav)
{
	quackbehavior = quackbehav;
}

void Duck::setFlyPerform(FlyBehavior* flybehav)
{
	flybehavior = flybehav;
}


void FlyBehavior::Fly()
{
}

void QuackBehavior::Quack()
{
}
