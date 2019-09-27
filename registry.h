#ifndef REGISTRY_H
#define REGISTRY_H

#include "Examples/examples.h"
#include "timer.h"

#include <map>
#include <string>

using callback = void (*)(void);

class FuncPtr
{
public:
    void (*f_normal)(void);
    void (*f_optimized)(void);
    void (*f_optimized_1)(void);
    void (*f_optimized_2)(void);
    void (*f_optimized_3)(void);
    void (*f_optimized_4)(void);
    void (*f_optimized_5)(void);
    void (*f_optimized_6)(void);
    void (*f_optimized_7)(void);

    FuncPtr()
    {
        f_normal      =
        f_optimized   =
        f_optimized_1 =
        f_optimized_2 =
        f_optimized_3 =
        f_optimized_4 =
        f_optimized_5 =
        f_optimized_6 =
        f_optimized_7 = nullptr;
    }

    FuncPtr(callback normal,
            callback opt,
            callback opt1 = nullptr,
            callback opt2 = nullptr,
            callback opt3 = nullptr,
            callback opt4 = nullptr,
            callback opt5 = nullptr,
            callback opt6 = nullptr,
            callback opt7 = nullptr)
    {
        f_normal      = normal;
        f_optimized   = opt;
        f_optimized_1 = opt1;
        f_optimized_2 = opt2;
        f_optimized_3 = opt3;
        f_optimized_4 = opt4;
        f_optimized_5 = opt5;
        f_optimized_6 = opt6;
        f_optimized_7 = opt7;
    }
};

class Registry
{
    std::map<std::string, FuncPtr> _map;

public:

    Registry();
    ~Registry();

    FuncPtr get(std::string key);

    static Registry * getInstance();
    static void destroyInstance();

private:

    static Registry * _instance;
};

#define InitRegistry() Registry::getInstance()
#define ReleaseRegisty() Registry::destroyInstance()

#define REGISTRY() Registry::getInstance()

#endif // REGISTRY_H
