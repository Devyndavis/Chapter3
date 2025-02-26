#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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
    // Initialize random seed
    std::srand(std::time(0)); 

    // Create a vector of 10 random numbers between 1 and 100
    std::vector<int> vec(10);
    for (int& num : vec) {
        num = std::rand() % 100 + 1;  // Random number between 1 and 100
    }

    // Sort the vector to enable binary search
    std::sort(vec.begin(), vec.end());

    // Randomly generate a target value
    int target = std::rand() % 100 + 1;  // Random target between 1 and 100

    // Display contents of the vector and target
    std::cout << "Contents of vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Random target: " << target << std::endl;

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, target, 0, vec.size() - 1);
    std::cout << "Recursive Binary Search: ";
    if (index != -1) {
        std::cout << "Target " << target << " found at location " << index << std::endl;
    } else {
        std::cout << "Target " << target << " was not found." << std::endl;
    }

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target);
    std::cout << "Iterative Binary Search: ";
    if (index != -1) {
        std::cout << "Target " << target << " found at location " << index << std::endl;
    } else {
        std::cout << "Target " << target << " was not found." << std::endl;
    }

    // Sequential Search
    index = sequentialSearch(vec, target);
    std::cout << "Sequential Search: ";
    if (index != -1) {
        std::cout << "Target " << target << " found at location " << index << std::endl;
    } else {
        std::cout << "Target " << target << " was not found." << std::endl;
    }

    return 0;
}