//
// Created by 21911 on 24-10-8.
//
#include <vector>
using namespace std;

int solution(const vector<int>& numbers) {
    // Check if the array has at least two elements
    if (numbers.size() < 2) {
        return 0;
    }

    // Get the first two elements
    int first = numbers[0];
    int second = numbers[1];

    // Initialize the count
    int count = 0;

    // Iterate through the array and count elements that are not equal to first or second
    for (const int& num : numbers) {
        if (num != first && num != second) {
            count++;
        }
    }

    return count;
}

// Example usage
#include <iostream>

int main() {
    cout << solution({4, 3, 2, 3, 2, 5, 4, 3}) << endl; // Output: 3
    cout << solution({3, 3, 1, 1, 3}) << endl;         // Output: 2
    cout << solution({-2}) << endl;                     // Output: 0
    return 0;
}
