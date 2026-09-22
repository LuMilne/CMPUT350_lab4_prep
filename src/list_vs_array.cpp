#include <cstddef>  // size_t
#include <random>
#include <list>
#include <iostream>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // -----
    // INSERT TEST
    // -----
    // Seed random generator
    std::mt19937_64 rng(0); // Seed=0

    // Test list insert time
    auto list = std::list<uint64_t>(16000000);  // Initialize list
    Timer stopwatch = Timer();
    for(uint64_t entry : list) {    // Insert
        entry = rng();
    }
    uint64_t listTime = stopwatch.glance<Timer::Seconds>();

    // Reseed generator (start test from same point)
    std::mt19937 seed(0);

    // Test array insert time
    auto array = std::vector<uint64_t>(16000000);   // Initialize array
    stopwatch.restart();
    for(uint64_t entry : array) {   // Insert
        entry = rng();
    }
    uint64_t arrayTime = stopwatch.click<Timer::Seconds>();

    std::cout << "List took " << listTime << " seconds to populate\n";
    std::cout << "Array took " << arrayTime << " seconds to populate\n";

    // -----
    // SUM TEST
    // -----

    // Sum list
    uint64_t listSum = 0;
    stopwatch.restart();
    for(uint64_t entry : list) {
        listSum += entry;
    }
    listTime = stopwatch.glance<Timer::Seconds>();

    // Sum array
    uint64_t arraySum = 0;
    stopwatch.restart();
    for(uint64_t entry : array) {
        arraySum += entry;
    }
    arrayTime = stopwatch.click<Timer::Seconds>();
    
    std::cout << "List (sum = " << listSum << ") took " << listTime << " seconds to populate\n";
    std::cout << "Array (sum = " << arraySum << ") took " << arraySum << " seconds to populate\n";

    return 0;
}
