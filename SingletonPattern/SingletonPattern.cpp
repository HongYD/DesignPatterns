// SingletonPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include"Singleton.h"

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!\n" <<
        "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
        "RESULT:\n";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();
    return 0;
}


