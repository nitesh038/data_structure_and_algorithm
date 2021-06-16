#include<iostream>
#include<string>
#include<math.h>
#include "profiler.h"

#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__PRETTY_FUNCTION__)
#else
#define PROFILE_SCOPE(name)
#endif

void function1()
{
    PROFILE_FUNCTION();
    for(int i=0; i<1000; i++)
        std::cout<<"Hello World" << i << std::endl;
}

void function2()
{
    PROFILE_FUNCTION();
    for(int i=0; i<1000; i++)
        std::cout<<"Hello World" << sqrt(i) << std::endl;
}

void RunBenchMarks()
{
    PROFILE_FUNCTION();
    std::cout<< "Running Benchmarks..\n";
    function1();
    function2();
}

void table()
{
    PROFILE_FUNCTION();
    for(int i=0; i<10000; i++)
        std::cout<< 2*(i) << std::endl;
}

int main()
{
    
    Instrumentor::Get().BeginSession("Profile");
    RunBenchMarks();
    Instrumentor::Get().EndSession();

    Instrumentor::Get().BeginSession("Profile_Another", "Results_another.json");
    table();
    Instrumentor::Get().EndSession();

    std::cin.get();

}