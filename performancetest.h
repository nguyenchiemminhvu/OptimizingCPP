#ifndef PERFORMANCETEST_H
#define PERFORMANCETEST_H

#include "registry.h"

#include <stdint.h>
#include <string>

typedef void (*callback_function)(void);

class PerformanceTest
{
public:

    static void run(std::string _namespace);
	static void run(int nTime, std::string _namespace);

private:

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
