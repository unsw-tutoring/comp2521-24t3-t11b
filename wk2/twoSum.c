#include <stdbool.h>
#include <stdio.h>

// return whether there are two numbers in the array that sum to 'sum'
// n = size of the array
bool hasTwoSum(int *arr, int n, int sum) {
    for (int i = 0; i < n; i++) {          // runs O(n) times
        for (int j = i + 1; j < n; j++) {  // runs O(n) times
            if (arr[i] + arr[j] == sum) {  // O(1)
                return true;
            }
        }
    }
    return false;
}
