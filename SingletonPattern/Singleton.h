#pragma once
#include<iostream>
#include <mutex>
#include<string>
#include<thread>
using namespace std;
class Singleton
{
private:
	static Singleton* pinstance_;
	static std::mutex mutex_;
protected:
	std::string value_;
	Singleton(const std::string value) :value_(value) {

	}
	~Singleton(){}

public:
	Singleton(Singleton& other) = delete;
	void operator=(const Singleton&) = delete;

	static Singleton* GetInstance(const std::string& value);
	std::string value() const {
		return value_;
	}

	void SomeBusinessLogic()
	{
		// ...
	}
};

Singleton* Singleton::GetInstance(const std::string& value)
{
	if (pinstance_ == nullptr)
	{
		std::lock_guard<std::mutex> lock(mutex_);
		if (pinstance_ == nullptr)
		{
			pinstance_ = new Singleton(value);
		}
	}
	return pinstance_;
}

Singleton* Singleton::pinstance_{ nullptr };
std::mutex Singleton::mutex_;

void ThreadFoo() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* singleton = Singleton::GetInstance("FOO");
	std::cout << singleton->value() << "\n";
}

void ThreadBar() {
	// Following code emulates slow initialization.
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* singleton = Singleton::GetInstance("BAR");
	std::cout << singleton->value() << "\n";
}


