// CRTP.cpp | https://www.youtube.com/watch?v=Srx4eiBdpdQ&t=196s
// Curiously Repeated Template Pattern (CRTP). 

#include <iostream>
#include "crtp_interface.h"
#include "normal_interface.h"
#include "icecream.hpp"

template <typename T, typename S>
void Benchmark(T& object, S function, const std::string& name)
{
    // Get starting time point
    auto start = std::chrono::high_resolution_clock::now();

    // Execute the function
    function(&object);

    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate time and output result
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    IC(name, duration.count());
}

int main()
{
    NormalImplemented object;
    Benchmark(object, RunNormal, "Normal Interface");

    CRTPImplemented object2;
    Benchmark(object2, RunCRTP<CRTPImplemented>, "CRTP Interface");

    system("pause");
}
