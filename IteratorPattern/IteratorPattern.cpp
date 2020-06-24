// IteratorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Iterator { // 迭代器抽象类
public:
    virtual string First() = 0;
    virtual string Next() = 0;
    virtual bool IsDone() = 0;
    virtual string CurrentItem() = 0;
    virtual ~Iterator() {}
};

class Aggregate { // 聚集抽象类
public:
    virtual Iterator* CreateIterator() = 0;
    virtual void Push(string s) = 0;
    virtual string Pop(int index);
    virtual int Count() = 0;
};

class ConcreteIterator : public Iterator { // 具体迭代器类
private:
    //需要一个抽象聚集类引用，可以被声明为各种各样的具体的聚集对象
    Aggregate* aggregate;
    int index;
public:
    ConcreteIterator(Aggregate* a) {
        index = 0;
        aggregate = a;
    }
    string First() { return aggregate->Pop(0); }
    string Next() {
        string str;
        index++;
        if (index < aggregate->Count()) 
            str = aggregate->Pop(index);
        return str;
    }
    bool IsDone() { return (index >= aggregate->Count()); }
    string CurrentItem() { return aggregate->Pop(index); }
};

/// <summary>
/// 具体的集合类
///具体集合类有不同种类的数据结构，以及一个迭代器接口
///实现抽象集合接口的各种函数，初始化适用于本集合的迭代器
/// </summary>
class ConcreteAggregate : public Aggregate {
private:
    //这里有不同的数据结构
    vector<string> items;
    //暴漏一个迭代器的接口
    Iterator* iterator;
public:
    ConcreteAggregate() {
        iterator = NULL;
        items.clear();
    }
    ~ConcreteAggregate() {
        if (iterator) {
            delete iterator;
            iterator = NULL;
        }
    }
    Iterator* CreateIterator() {
        if (iterator == NULL) iterator = new ConcreteIterator(this);
        return iterator;
    }
    int Count() { return items.size(); }
    void Push(string s) { items.push_back(s); }
    string Pop(int index) {
        string str;
        if (index < Count()) 
            str = items[index];
        return str;
    }
};


//class ConcreteAggregateInt :Aggregate {
//private:
//    vector<int>items;
//    Iterator* it;
//public:
//    ConcreteAggregateInt() {
//        items.clear();
//        it = NULL;
//    }
//    ~ConcreteAggregateInt() {
//        if (it) {
//            delete it;
//            it = NULL;
//        }
//    }
//    Iterator* CreateIterator() {
//        if (it == NULL) {
//            it = new ConcreteIterator(this);
//        }
//        return it;
//    }
//
//    int Count() {
//        return this->items.size();
//    }
//
//    void Push(int i) { items.push_back(i); }
//    int Pop(int i) {
//        int temp;
//        if (i < Count()) {
//            temp = items[i];
//        }
//        return temp;
//    }
//};

int main() {
    ConcreteAggregate* ca = new ConcreteAggregate();
    ca->Push("Hello");
    ca->Push("World");
    ca->Push("你好");

    Iterator* it = new ConcreteIterator(ca);
    while (!it->IsDone()) {
        cout << it->CurrentItem() << endl;
        it->Next();
    }

    delete it;
    delete ca;
    return 0;
}


