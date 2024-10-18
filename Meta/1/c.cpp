//
// Created by 21911 on 24-10-8.
//
#include <bits/stdc++.h>

using namespace std;

// Function to swap two rows in the matrix
void swapRows(vector<vector<int>>& matrix, int r1, int r2) {
    swap(matrix[r1], matrix[r2]);
}

// Function to swap two columns in the matrix
void swapColumns(vector<vector<int>>& matrix, int c1, int c2) {
    for (int i = 0; i < matrix.size(); ++i) {
        swap(matrix[i][c1], matrix[i][c2]);
    }
}

// Function to reverse a specific row in the matrix
void reverseRow(vector<vector<int>>& matrix, int r) {
    reverse(matrix[r].begin(), matrix[r].end());
}

// Function to reverse a specific column in the matrix
void reverseColumn(vector<vector<int>>& matrix, int c) {
    for (int i = 0; i < matrix.size() / 2; ++i) {
        swap(matrix[i][c], matrix[matrix.size() - 1 - i][c]);
    }
}

// Function to rotate the matrix 90 degrees clockwise
void rotate90Clockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> rotated(m, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = rotated;
}

// Main function to process commands on the matrix
vector<vector<int>> solution(vector<vector<int>>& matrix, const vector<string>& commands) {
    for (const string& command : commands) {
        stringstream ss(command);
        string operation;
        ss >> operation;

        if (operation == "swapRows") {
            int r1, r2;
            ss >> r1 >> r2;
            swapRows(matrix, r1, r2);
        } else if (operation == "swapColumns") {
            int c1, c2;
            ss >> c1 >> c2;
            swapColumns(matrix, c1, c2);
        } else if (operation == "reverseRow") {
            int r;
            ss >> r;
            reverseRow(matrix, r);
        } else if (operation == "reverseColumn") {
            int c;
            ss >> c;
            reverseColumn(matrix, c);
        } else if (operation == "rotate90clockwise") {
            rotate90Clockwise(matrix);
        }
        for (const auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return matrix;
}

// Example usage
int main() {
    vector<vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
    };
    vector<string> commands = {
            "swapRows 0 2",
            "swapColumns 1 2",
            "reverseRow 0",
            "reverseColumn 2",
            "rotate90clockwise"
    };

    vector<vector<int>> result = solution(matrix, commands);

    // Print the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
