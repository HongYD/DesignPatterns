// ObserverPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"Subject.h"
#include"WeatherData.h"

int main()
{
    WeatherData* weatherData = new WeatherData();
    CurrentConditionDisplay* currentCond = new CurrentConditionDisplay(weatherData);
    weatherData->registerObserver(currentCond);
    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->notifyObservers();

    weatherData->setMeasurements(82, 70, 29.2f);
    weatherData->notifyObservers();

    weatherData->setMeasurements(78, 90, 29.2f);
    weatherData->notifyObservers();

}

