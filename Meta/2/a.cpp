//
// Created by 21911 on 24-10-8.
//
#include <bits/stdc++.h>

using namespace std;
int findHowManySubarraysMatchThePattern(vector<int> numbers, vector<int> pattern) {
    vector<int> a;
    int n = numbers.size();
    for(int i = 0; i < n - 1; i ++) a.push_back(numbers[i+1] - numbers[i] > 0 ? 1 : (numbers[i+1] - numbers[i] == 0 ? 0 : -1));
    int m = pattern.size(), res = 0;
    for(int i = 0; i < n - 1; i ++) cout << a[i] << " "; cout <<endl;
    for(int i = 0; i <= n - 1 - m; i ++) {
        int j = 0;
        int k = i;
        while(j < m && a[k] == pattern[j]) k ++, j ++;
        if(j == m) res ++;
    }
    return res;
}

int main(void) {
    vector<int> houses = {4, 1, 3, 4, 4, 5, 5 ,1};
    vector<int> ops = {1, 0, -1};
    cout << findHowManySubarraysMatchThePattern(houses, ops) << endl;
}