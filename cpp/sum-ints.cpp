#include <chrono>
#include <iostream>
#include <stdlib.h>

static long nums_size = 1000000;
static int repeat_num = 5000;
static int candidate_num = 20;

int main(int argc, char **argv) {
    int * nums[candidate_num];
    int selected_candidate[repeat_num];

    for (int i = 0; i < candidate_num; i++) {
        nums[i] = new int[nums_size];
        int * num_arr = nums[i];
        for (int j = 0; j < nums_size; j++) {
            num_arr[j] = rand();
        }
    }
    for (int i = 0; i < repeat_num; i++) {
        selected_candidate[i] = rand() % candidate_num;
    }

    long sum = 0;
    auto start = std::chrono::system_clock::now();
    for (int r = 0; r < repeat_num; r++) {
        int * num_arr = nums[selected_candidate[r]];
        for (int i = 0; i < nums_size; i++) {
            sum += num_arr[i];
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
