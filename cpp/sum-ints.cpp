#include <chrono>
#include <iostream>
#include <stdlib.h>

static long nums_size = 1000000;

int main(int argc, char **argv) {
    int nums[nums_size];

    for (int i = 0; i < nums_size; i++) {
        nums[i] = rand();
    }

    long sum = 0;
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < nums_size; i++) {
        sum += nums[i];
    }
    auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start);
    std::cout << "duration: " << time_span.count() << " MicroSec" << std::endl;
    std::cout << sum << std::endl;

    return 0;
}
