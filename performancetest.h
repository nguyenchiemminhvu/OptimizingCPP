#ifndef PERFORMANCETEST_H
#define PERFORMANCETEST_H

#include <stdint.h>

#define N_TIME 100000000

typedef void (*callback_function)(void);

class PerformanceTest
{
public:

    static void run(callback_function normalFunc = nullptr, callback_function optimizedFunc = nullptr);

};

#endif // PERFORMANCETEST_H
