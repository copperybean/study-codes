#include <chrono>
#include <iostream>
#include <stdlib.h>

static long nums_size = 1000000;
static int repeat_num = 5000;

int main(int argc, char **argv) {
    int nums[nums_size];
    long modify_pos[repeat_num];
    long modify_val[repeat_num];

    for (int i = 0; i < nums_size; i++) {
        nums[i] = rand();
    }

    for (int i = 0; i < repeat_num; i++) {
        modify_pos[i] = rand() % nums_size;
        modify_val[i] = rand();
    }

    long sum = 0;
    auto start = std::chrono::system_clock::now();
    for (int r = 0; r < repeat_num; r++) {
        nums[modify_pos[r]] = modify_val[r];
        for (int i = 0; i < nums_size; i++) {
            sum += nums[i];
        }
    }
    auto span_raw = std::chrono::system_clock::now() - start;
    auto span_micro_sec = std::chrono::duration_cast<std::chrono::microseconds>(span_raw);
    auto span_milli_sec = std::chrono::duration_cast<std::chrono::milliseconds>(span_raw);
    std::cout << "duration: " << span_milli_sec.count() << " milli seconds (" <<
            span_micro_sec.count() << " micro seconds)" << std::endl;
    std::cout << sum << std::endl;

    return 0;
}
