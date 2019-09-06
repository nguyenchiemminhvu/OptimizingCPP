#include "timer.h"
#include <iostream>

Timer * Timer::_instance = nullptr;

Timer::Timer()
{
    _type = DurationType::MILISECONDS;
}

Timer::~Timer()
{

}

void Timer::setType(DurationType type)
{
    _type = type;
}

void Timer::start()
{
    _startTime = clock::now();
}

void Timer::stop()
{
    _endTime = clock::now();
    _duration = _endTime - _startTime;

    // print log
    switch (_type) {
    case DurationType::NANOSECONDS:
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(_duration).count() << " (nanoseconds)" << std::endl;
        break;
    case DurationType::MICROSECONDS:
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(_duration).count() << " (microseconds)" << std::endl;
        break;
    case DurationType::MILISECONDS:
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(_duration).count() << " (miliseconds)" << std::endl;
        break;
    case DurationType::SECONDS:
        std::cout << std::chrono::duration_cast<std::chrono::seconds>(_duration).count() << " (seconds)" << std::endl;
        break;
    case DurationType::MINUTES:
        std::cout << std::chrono::duration_cast<std::chrono::minutes>(_duration).count() << " (seconds)" << std::endl;
        break;
    case DurationType::HOURS:
        std::cout << std::chrono::duration_cast<std::chrono::hours>(_duration).count() << " (seconds)" << std::endl;
        break;

    default:
        break;
    }
}

Timer * Timer::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Timer();
    }

    return _instance;
}

void Timer::destroyInstance()
{
    if (_instance)
    {
        delete _instance;
        _instance = nullptr;
    }
}
