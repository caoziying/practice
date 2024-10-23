//
// Created by NK on 24-10-23.
//
/*
 * 合并石子，每个石子有一个权值，每次合并两个相邻石子之后，权值变为 ai - aj，求最后的最大权值
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0; i < n; i ++) cin >> v[i];
    int z = 0, f = 0, zero = 0;
    for(auto x : v) {
        if(x == 0) zero ++;
        if(x > 0) z ++;
        if(x < 0) f ++;
    }
    ll res = 0, mn = LLONG_MAX;
    for(auto x : v) res += abs(x), mn = min(mn, abs(x));
    if(z && f || (z+f > 0 && zero)) {
        cout << res << endl;
    }
    else {
        cout << res - mn << endl;
    }
}