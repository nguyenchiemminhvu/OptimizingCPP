#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
    using clock = std::chrono::high_resolution_clock;
    using clock_t = std::chrono::time_point<std::chrono::high_resolution_clock>;
    using duration_t = std::chrono::time_point<std::chrono::high_resolution_clock>::duration;

public:

    enum class DurationType
    {
        NANOSECONDS,
        MICROSECONDS,
        MILISECONDS,
        SECONDS,
        MINUTES,
        HOURS,
    };

    void setType(DurationType type = DurationType::MILISECONDS);
    void start();
    void stop();

    static Timer * getInstance();
    static void destroyInstance();

private:

    DurationType _type;
    clock_t _startTime;
    clock_t _endTime;
    duration_t _duration;

private:

    static Timer *_instance;

    Timer();
    ~Timer();
};

#define GetTimer() Timer::getInstance()
#define ReleaseTimer() Timer::destroyInstance()

#endif // TIMER_H
