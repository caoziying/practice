//
// Created by 21911 on 24-8-23.
//
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
int t[400010];
int lb(int x) {return x & -x;}
void update(int x, int val) {
    while(x < 400010) {
        t[x] += val;
        x += lb(x);
    }
}
int pre(int x) {
    int res = 0;
    while(x) {
        res += t[x];
        x -= lb(x);
    }
    return res;
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(2 * n + 10);
    unordered_map<ll, int> mp;
    for(int i = 1; i <= n; i ++) cin >> a[i], mp[a[i]] ++;
    for(int i = n + 1; i <= 2 * n; i ++) a[i] = a[i-n];
    // t.resize(2 * n + 10, 0);
    vector<pair<ll, ll>> query(q + 1);
    vector<int> idx(q + 1);
    vector<int> res(q + 1);
    char ch;
    int x;
    ll l = 1, r = 2 * n;
    for(int i = 1; i <= q; i ++) {
        idx[i] = i;
        cin >> ch >> x;
        if(x >= n) res[i] = mp.size(), query[i] = {0, 0};
        if(ch == 'L') {
            if(x < n) query[i] = {l, l + x - 1};
            l += (x % n);
            if(l > n) l -= n;
        }
        else {
            if(x < n) query[i] = {r - x + 1, r};
            r -= (x % n);
            if (r < n) r += n;
        }
    }
    sort(idx.begin() + 1, idx.end(), [&](int i, int j){
        return query[i].second < query[j].second;
    });
    int j = 1;
    unordered_map<ll, int> pos;
    for(int i = 1; i <= q; i ++) {
        int l = query[idx[i]].first, r = query[idx[i]].second;
//         cout << l << " " << r << endl;
        if(l == r && r == 0) continue;
        while(j <= r) {
            if(pos.find(a[j]) != pos.end()) {
                update(pos[a[j]], -1);
                pos[a[j]] = j;
                update(j, 1);
            }
            else {
                pos[a[j]] = j;
                update(j, 1);
            }
            j ++;
        }
        res[idx[i]] = pre(r) - pre(l-1);
    }
    // for(int i = 1; i <= q; i ++) cout << query[i].first << " " << query[i].second << endl;
    for(int i = 1; i <= q; i ++) cout << res[i] << endl;
}
// 64 位输出请用 printf("%lld")