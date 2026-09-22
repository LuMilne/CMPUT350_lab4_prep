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
    auto list = std::list<uint64_t>();  // Initialize list
    Timer stopwatch = Timer();
    for(int i = 0; i < 16000000; i++) {    // Insert
        list.push_back(rng());
    }
    uint64_t listTime = stopwatch.glance<Timer::Millis>();

    // Reseed generator (start test from same point)
    std::mt19937 seed(0);

    // Test array insert time
    auto array = std::vector<uint64_t>();   // Initialize array
    stopwatch.restart();
    for(int i = 0; i < 16000000; i++) {    // Insert
        array.push_back(rng());
    }
    uint64_t arrayTime = stopwatch.click<Timer::Millis>();

    std::cout << "List took " << listTime << " ms to populate\n";
    std::cout << "Array took " << arrayTime << " ms to populate\n";

    // -----
    // SUM TEST
    // -----

    // Sum list
    uint64_t listSum = 0;
    stopwatch.restart();
    for(uint64_t entry : list) {
        listSum += entry;
    }
    listTime = stopwatch.glance<Timer::Millis>();

    // Sum array
    uint64_t arraySum = 0;
    stopwatch.restart();
    for(uint64_t entry : array) {
        arraySum += entry;
    }
    arrayTime = stopwatch.click<Timer::Millis>();
    
    std::cout << "List (sum = " << listSum << ") took " << listTime << " ms to populate\n";
    std::cout << "Array (sum = " << arraySum << ") took " << arrayTime << " ms to populate\n";

    return 0;
}
