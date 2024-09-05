//
// Created by 21911 on 24-9-5.
//
//给定一个数组a，规定一个好数组满足任意连续k个元素的总和不超过sum，现在可以执行任意次更改，每次可以选择一个元素-1，
//求最少执行多少次操作，使得数组变为一个好数组,数组元素不能为负数，且 n <= 1e5

//思路：双端队列维护大小为K的滑动窗口，总和超过sum时，则优先操作最新插入队列的元素，及时删除不在范围内的元素
#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int main() {
    int n, k;
    ll sum;
    cin >> n >> k >> sum;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll s = 0, res = 0;
    deque<pair<int, ll>> sta;
    for (int i = 1; i <= k; i++) sta.push_back({i, a[i]}), s += a[i];
    for (int i = k + 1; i <= n; i++) {
        while (s > sum) {
            while (s - sta.back().second > sum)
                s -= sta.back().second, res += sta.back().second, sta.pop_back();
            sta.back().second -= (s - sum), res += (s - sum);
            s = sum;
        }
        if (sta.front().first <= i - k) {
            s -= sta.front().second;
            sta.pop_front();
        }
        sta.push_back({i, a[i]});
        s += a[i];
    }
    while (s > sum) {
        while (s - sta.back().second > sum)
            s -= sta.back().second, res += sta.back().second, sta.pop_back();
        sta.back().second -= (s - sum), res += (s - sum);
        s = sum;
    }
    cout << res << endl;
}
/* 例：
5 3 10
9 7 3 6 5
10
*/