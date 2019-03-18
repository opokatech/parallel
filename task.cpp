#include <algorithm> // sort
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <functional>

#include <parallel/algorithm> // __gnu_parallel::sort

using VTYPE = double;

constexpr size_t testSize = 10'000'000;
constexpr int iterationCount = 5;

auto getTime() { return std::chrono::high_resolution_clock::now(); }

double durationMs(const std::chrono::high_resolution_clock::time_point& a_t1,
    const std::chrono::high_resolution_clock::time_point& a_t2)
{
    using namespace std::chrono;
    return duration_cast<duration<double, std::milli>>(a_t2 - a_t1).count();
}

void printResults(const char* const a_tag, const std::vector<VTYPE>& a_list,
    std::chrono::high_resolution_clock::time_point a_t1, std::chrono::high_resolution_clock::time_point a_t2)
{
    using namespace std;

    cout << a_tag << " Lowest: " << a_list.front() << ", highest: " << a_list.back()
         << ", time: " << durationMs(a_t1, a_t2) << "ms" << endl;
}

void sort_parallel(std::vector<VTYPE> &a_list)
{
    __gnu_parallel::sort(a_list.begin(), a_list.end());
}

void sort_serial(std::vector<VTYPE> &a_list)
{
    std::sort(a_list.begin(), a_list.end());
}

void runTest(bool a_parallel, const std::vector<VTYPE> &a_numbers)
{
    const char *tag = a_parallel? "Parallel ": "Serial   ";

    auto sort_fn = (a_parallel? sort_parallel: sort_serial);

    for (int i = 0; i < iterationCount; ++i) {
        std::vector<VTYPE> sorted(a_numbers);
        const auto startTime = getTime();
        sort_fn(sorted);
        const auto endTime = getTime();
        printResults(tag, sorted, startTime, endTime);
    }
}

void runTestSerial(const std::vector<VTYPE> &a_numbers)
{
    runTest(false, a_numbers);
}

void runTestParallel(const std::vector<VTYPE> &a_numbers)
{
    runTest(true, a_numbers);
}

int main()
{
    std::random_device rd;

    std::cout << "Generating " << testSize << " numbers..." << std::flush;

    std::vector<VTYPE> numbers(testSize);
    {
        const auto startTime = getTime();
        std::generate(numbers.begin(), numbers.end(), [&rd] { return rd(); });
        const auto endTime = getTime();

        std::cout << "done (" << durationMs(startTime, endTime) << ")" << std::endl << std::flush;
    }

    runTestSerial(numbers);
    runTestParallel(numbers);

    return 0;
}
