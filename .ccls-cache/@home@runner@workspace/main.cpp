#include <iostream>
#include <vector>
#include <algorithm>

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
    // Test Data
    std::vector<int> vec = {15, 22, 9, 3, 5, 7};  // Unsigned vector
    std::sort(vec.begin(), vec.end());  // Sort the vector to enable binary search

    int target1 = 9;  // Target that is in the list
    int target2 = 12; // Target that is not in the list

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, target1, 0, vec.size() - 1);
    std::cout << "Target " << target1 << " found at location " << index << std::endl;
    index = recursiveBinarySearch(vec, target2, 0, vec.size() - 1);
    std::cout << "Target " << target2 << " was not found, return value is " << index << std::endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target1);
    std::cout << "Target " << target1 << " found at location " << index << std::endl;
    index = iterativeBinarySearch(vec, target2);
    std::cout << "Target " << target2 << " was not found, return value is " << index << std::endl;

    // Sequential Search
    index = sequentialSearch(vec, target1);
    std::cout << "Target " << target1 << " found at location " << index << std::endl;
    index = sequentialSearch(vec, target2);
    std::cout << "Target " << target2 << " was not found, return value is " << index << std::endl;

    return 0;
}