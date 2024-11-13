//
// Created by NK on 24-10-23.
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n;
    int t = 4, x = 2, y = 2;
    int res = 0;
    if(t > 0) res ++;
    res += min(x, t-1);    // left  至少一个, right 没有
    res += min(y, t-1);    // right 至少一个, left  没有
    int k = min(x, t-2);   // 左边最多能取 k 个
    if(k > 0) {
        if(t - k >= y) res += y * k;
        else if(t - 2 <= y) res += (t - 2 + t - k) * (k - 1) / 2;
        else res += (t - 2 + y) * (y - t + 2 + 1) / 2 + ((k-1) - (y - (t-2) + 1)) * y;
    }
    cout << res << endl;
}
