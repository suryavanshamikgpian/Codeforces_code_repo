#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Cycle Sort
void cycleSort(std::vector<int>& arr, int n) {
    for (int cycle_start = 0; cycle_start <= n - 2; ++cycle_start) {
        int item = arr[cycle_start];
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; ++i) {
            if (arr[i] < item) {
                ++pos;
            }
        }
        if (pos == cycle_start) {
            continue;
        }
        while (item == arr[pos]) {
            ++pos;
        }
        if (pos != cycle_start) {
            std::swap(item, arr[pos]);
        }
        while (pos != cycle_start) {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; ++i) {
                if (arr[i] < item) {
                    ++pos;
                }
            }
            while (item == arr[pos]) {
                ++pos;
            }
            if (item != arr[pos]) {
                std::swap(item, arr[pos]);
            }
        }
    }
}

int main() {
    std::vector<int> arr1 = {10, 7, 8, 9, 1, 5};
    int n1 = arr1.size();
    quickSort(arr1, 0, n1 - 1);
    std::cout << "Sorted array using Quick Sort: ";
    for (int x : arr1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = {4, 3, 2, 1};
    int n2 = arr2.size();
    cycleSort(arr2, n2);
    std::cout << "Sorted array using Cycle Sort: ";
    for (int x : arr2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}