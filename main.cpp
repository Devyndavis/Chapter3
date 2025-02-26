#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Recursive Binary Search
int recursiveBinarySearch(const std::vector<int>& vec, int target, int low, int high) {
    if (low > high) return -1; // target not found
    int mid = low + (high - low) / 2;
    if (vec[mid] == target) return mid;
    if (vec[mid] > target) return recursiveBinarySearch(vec, target, low, mid - 1);
    return recursiveBinarySearch(vec, target, mid + 1, high);
}

// Iterative Binary Search
int iterativeBinarySearch(const std::vector<int>& vec, int target) {
    int low = 0, high = vec.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (vec[mid] == target) return mid;
        if (vec[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1; // target not found
}

// Sequential Search
int sequentialSearch(const std::vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) return i;
    }
    return -1; // target not found
}

int main() {
    std::srand(std::time(0));  // Initialize random seed

    // Variables to accumulate times
    double SumRBS = 0, SumIBS = 0, SumSeqS = 0;

    // Number of iterations
    int iterations = 10;

    // Run the experiment for different values of N
    std::vector<int> N_values = {5000, 50000, 100000, 150000, 1000000};

    // Loop through different N values
    for (int N : N_values) {
        SumRBS = SumIBS = SumSeqS = 0;  // Reset sums for each N

        for (int i = 0; i < iterations; ++i) {
            // Generate a vector with N random numbers
            std::vector<int> vec(N);
            for (int& num : vec) {
                num = std::rand() % 100 + 1;  // Random number between 1 and 100
            }

            // Sort the vector for binary search
            std::sort(vec.begin(), vec.end());

            // Generate a random target value
            int target = std::rand() % 100 + 1;

            // Measure time for Recursive Binary Search
            auto start = std::chrono::high_resolution_clock::now();
            recursiveBinarySearch(vec, target, 0, vec.size() - 1);
            auto end = std::chrono::high_resolution_clock::now();
            SumRBS += std::chrono::duration<double, std::micro>(end - start).count();

            // Measure time for Iterative Binary Search
            start = std::chrono::high_resolution_clock::now();
            iterativeBinarySearch(vec, target);
            end = std::chrono::high_resolution_clock::now();
            SumIBS += std::chrono::duration<double, std::micro>(end - start).count();

            // Measure time for Sequential Search
            start = std::chrono::high_resolution_clock::now();
            sequentialSearch(vec, target);
            end = std::chrono::high_resolution_clock::now();
            SumSeqS += std::chrono::duration<double, std::micro>(end - start).count();
        }

        // Output average times for each algorithm for current N
        std::cout << "For N = " << N << ":\n";
        std::cout << "Average Running Time for Recursive Binary Search in microseconds: " << SumRBS / iterations << std::endl;
        std::cout << "Average Running Time for Iterative Binary Search in microseconds: " << SumIBS / iterations << std::endl;
        std::cout << "Average Running Time for Sequential Search in microseconds: " << SumSeqS / iterations << std::endl;
        std::cout << std::endl;
    }

    return 0;
}