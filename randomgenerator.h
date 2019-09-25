#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <chrono>
#include <random>
#include <time.h>
#include <stdint.h>
#include <limits.h>

#define RANDOM_MIN 0x00000000
#define RANDOM_MAX 0xFFFFFFFF

class RandomGenerator
{
public:
    RandomGenerator();
    ~RandomGenerator();

    int generate(int min, int max);

    static RandomGenerator * getInstance();

private:

    static RandomGenerator * _instance;
};

#define RANDOM()    RandomGenerator::getInstance()->generate(RANDOM_MIN, RANDOM_MAX)

#endif // RANDOMGENERATOR_H
