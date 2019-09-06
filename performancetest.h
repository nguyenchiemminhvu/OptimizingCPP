#ifndef PERFORMANCETEST_H
#define PERFORMANCETEST_H

#define N_TIME 1000000

typedef void (*callback_function)(void);

class PerformanceTest
{
public:

    static void run(int nTime, callback_function normalFunc = nullptr, callback_function optimizedFunc = nullptr);

};

#endif // PERFORMANCETEST_H
