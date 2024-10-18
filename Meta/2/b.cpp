//
// Created by 21911 on 24-10-8.
//
#include <bits/stdc++.h>

using namespace std;

int minimumObstaclesToRemoveToAllowFigureFall(vector<vector<char>> a) {
    int m = a.size(), n = a[0].size(), res = 0;
    for(int i = 0; i < n; i ++) {
        int j = m - 1;
        while(j >= 0 && a[j][i] == '#') j --, res ++;
    }
    return res;
}

int main(void) {
    vector<vector<char>> houses = {{'*', '*', '*'}, {'#', '*', '*'}, {'-', '-', '-'}, {'-', '#', '#'}};
    cout << minimumObstaclesToRemoveToAllowFigureFall(houses);
}