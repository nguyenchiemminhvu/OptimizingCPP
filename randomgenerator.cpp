#include "randomgenerator.h"

RandomGenerator * RandomGenerator::_instance = nullptr;

RandomGenerator * RandomGenerator::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new RandomGenerator();
    }
    return _instance;
}

RandomGenerator::RandomGenerator()
{

}

RandomGenerator::~RandomGenerator()
{

}

int RandomGenerator::generate(int min, int max)
{
    return (int)rand() % max + min;
}

