#include "PMergeMe.hpp"
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <iomanip>

long long get_time_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (static_cast<long long>(tv.tv_sec) * 1000000) + tv.tv_usec;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: No numbers provided." << std::endl;
        return 1;
    }

    std::vector<int> input_data;
    for (int i = 1; i < ac; i++) {
        char *endptr;
        long val = std::strtol(av[i], &endptr, 10);
        if (*endptr != '\0' || val < 0) {
            std::cerr << "Error: Invalid input '" << av[i] << "'" << std::endl;
            return 1;
        }
        input_data.push_back(static_cast<int>(val));
    }

    PMergeMe pmm;
    pmm.insertVec(input_data);
    pmm.insertList(input_data);

    std::cout << "Before: ";
    pmm.printVec(); // Assuming this prints the unsorted state
    std::cout << std::endl;

    // --- Vector Timing ---
    long long start = get_time_us();
    pmm.sortVec();
    long long end = get_time_us();
    long long timeVec = end - start;

    // --- List Timing ---
    start = get_time_us();
    pmm.sortList();
    end = get_time_us();
    long long timeList = end - start;

    std::cout << "After:  ";
    pmm.printVec();
    std::cout << std::endl;

    std::cout << "Time to process a range of " << input_data.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << input_data.size() 
              << " elements with std::list   : " << timeList << " us" << std::endl;

    pmm.checkSorted();
    return 0;
}