//
// Created by 21911 on 24-8-15.
//
#include <bits/stdc++.h>

using namespace std;
int fun1(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<>> q;
    for(int i = 0; i < k; i ++) q.push(arr[i]);
    for(int i = k; i < n; i ++) {
        if(q.top() < arr[i]) q.pop(), q.push(arr[i]);
    }
    int res = 0;
    while(q.size()) res += q.top(), q.pop();
    return res;
}
// 第 k 大的数
int kth_greater(vector<int>& arr, int l, int r, int k) {
    if(l == r) return arr[l];
    int mid = arr[(l + r) / 2];
    int i = l - 1, j = r + 1;
    while(i < j) {
        do i ++; while(arr[i] < mid);
        do j --; while(arr[j] > mid);
        if(i < j) swap(arr[i], arr[j]);
    }
    if(j - l + 1 >= k) return kth_greater(arr, l, j, k);
    else return kth_greater(arr, j+1, r, k - (j - l + 1));
}

int fun2(vector<int>& arr, int k) {
    int res = 0;
    int x = kth_greater(arr, 0, arr.size()-1, arr.size() - k + 1);
    for(auto e : arr) if(e >= x) res += e;
    return res;
}

int main(void) {
    vector<int> arr = {2, 3, 1, 5, 4, 21, 2, 9, 27};
    cout << fun1(arr, 3) << endl;
    cout << fun2(arr, 3) << endl;
}