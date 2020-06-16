#pragma once
#include<iostream>
#include<vector>
#include"Subject.h"
using namespace std;
class WeatherData:public Subject
{
private:
	vector<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;

public:
	WeatherData();
	void registerObserver(Observer* o);
	void removeObserver(Observer* o);
	void notifyObservers();
	void measurementsChanged();
	void setMeasurements(float temperature, float humidity, float pressure);
	float getTemperature();
	float gethumidity();
	float getPressure();
};

class CurrentConditionDisplay :public Observer, public DisplayElement {
private:
	float temperature;
	float humidity;
	Subject* weatherData;

public:
	CurrentConditionDisplay(Subject* wd);
	void update(float temperature, float humidity, float pressure);
	void display();
};

