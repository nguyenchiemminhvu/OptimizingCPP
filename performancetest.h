#ifndef PERFORMANCETEST_H
#define PERFORMANCETEST_H

#include <stdint.h>

typedef void (*callback_function)(void);

class PerformanceTest
{
public:

    static void run(int nTime,
                    callback_function normalFunc  = nullptr,
                    callback_function optimized   = nullptr,
                    callback_function optimized_1 = nullptr,
                    callback_function optimized_2 = nullptr,
                    callback_function optimized_3 = nullptr,
                    callback_function optimized_4 = nullptr,
                    callback_function optimized_5 = nullptr,
                    callback_function optimized_6 = nullptr,
                    callback_function optimized_7 = nullptr);

};

#endif // PERFORMANCETEST_H
