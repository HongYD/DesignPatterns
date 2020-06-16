#include "WeatherData.h"
#include<iostream>
using namespace std;

WeatherData::WeatherData()
{

}

void WeatherData::registerObserver(Observer* o)
{
	observers.push_back(o);
}

void WeatherData::removeObserver(Observer* o)
{
	int i=0;
	std::vector<Observer*>::iterator itr = std::find(observers.begin(), observers.end(), o);
	if (itr != observers.cend())
		i = std::distance(observers.begin(), itr);
	observers.erase(observers.begin() + i);
}

void WeatherData::notifyObservers()
{
	for (int i = 0; i < observers.size(); i++) {
		Observer* ob = observers.at(i);
		ob->update(temperature, humidity, pressure);
	}
}

void WeatherData::measurementsChanged()
{
	notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
}

float WeatherData::getTemperature()
{
	return this->temperature;
}

float WeatherData::gethumidity()
{
	return this->humidity;
}

float WeatherData::getPressure()
{
	return this->pressure;
}

CurrentConditionDisplay::CurrentConditionDisplay(Subject* wd)
{
	this->weatherData = wd;
	wd->registerObserver(this);
}

void CurrentConditionDisplay::update(float temperature, float humidity, float pressure)
{
	this->temperature = temperature;
	this->humidity = humidity;
	display();
}

void CurrentConditionDisplay::display()
{
	cout << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity" << endl;
}
