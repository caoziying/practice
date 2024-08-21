//
// Created by 21911 on 24-8-20.
//
//
// Created by 21911 on 2024/8/13.
//
#include <bits/stdc++.h>

#define eps 1e-8    //多2
#define inf 0x3f3f3f3f
#define PI acos(-1)     //π
#define f0n(i,n) for (int (i)=0;(i)< (n);(i)++)
#define f1n(i,n) for (int (i)=1;(i)<=(n);(i)++)

using namespace std;
// unordered_map  HASH,与时间戳相关，防止HACK
struct HASH {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    static size_t get(const uint64_t x) {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    template <typename T>
    size_t operator()(T x) const {
        return get(std::hash<T>()(x));
    }

    template <typename F, typename S>
    size_t operator()(pair<F, S> p) const {
        return get(std::hash<F>()(p.first) ^ std::hash<S>()(p.second));
    }
};
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

int TEST;               //测试案例数
const int N = 1e5+5;    //数组长度
//int a[N];
int n, m, k;
// int a, b, c;
// unordered_map<int, int, HASH> mp;
// unordered_map<pair<int, int>, int, HASH> mp2;
struct node {
    int mn, mx;
    int idx_mn, idx_mx;
};
vector<node> t, clr;
void update(int o, int l, int r, int x, int val) {
    if(l == r) {
        if(val == INT_MAX) {
            t[o].mx = -400000;
            t[o].mn = 400000;
            t[o].idx_mx = t[o].idx_mn = x;
        }
        else {
            t[o].mx = t[o].mn = val;
            t[o].idx_mx = t[o].idx_mn = x;
        }
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid) update(2 * o, l, mid, x, val);
    else update(2 * o + 1, mid + 1, r, x, val);
    if(t[2 * o].mx < t[2 * o + 1].mx) t[o].mx = t[2 * o + 1].mx, t[o].idx_mx = t[2 * o + 1].idx_mx;
    else t[o].mx = t[2 * o].mx, t[o].idx_mx = t[2 * o].idx_mx;
    if(t[2 * o].mn > t[2 * o + 1].mn) t[o].mn = t[2 * o + 1].mn, t[o].idx_mn = t[2 * o + 1].idx_mn;
    else t[o].mn = t[2 * o].mn, t[o].idx_mn = t[2 * o].idx_mn;
}
PII query_mx(int o, int l, int r, int L, int R) {
    if(l == L && r == R) {
        return {t[o].mx, t[o].idx_mx};
    }
    int mid = (l + r) / 2;
    if(R <= mid) return query_mx(2 * o, l, mid, L, R);
    else if(L > mid) return query_mx(2 * o + 1, mid + 1, r, L, R);
    else {
        auto [x, ix] = query_mx(2 * o, l, mid, L, mid);
        auto [y, iy] = query_mx(2 * o + 1, mid + 1, r, mid + 1, R);
        if(x < y) return {y, iy};
        else return {x, ix};
    }
}
PII query_mn(int o, int l, int r, int L, int R) {
    if(l == L && r == R) {
        return {t[o].mn, t[o].idx_mn};
    }
    int mid = (l + r) / 2;
    if(R <= mid) return query_mn(2 * o, l, mid, L, R);
    else if(L > mid) return query_mn(2 * o + 1, mid + 1, r, L, R);
    else {
        auto [x, ix] = query_mn(2 * o, l, mid, L, mid);
        auto [y, iy] = query_mn(2 * o + 1, mid + 1, r, mid + 1, R);
        if(x > y) return {y, iy};
        else return {x, ix};
    }
}
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // ll res = 0;
    // ########## wirte your code here ###########
    cin >> n;
    clr.resize(4 * n);
    t = clr;
    vector<int> a(n + 2), last;
    unordered_map<int, int, HASH> mp;
    unordered_map<int, vector<int>, HASH> id;
    unordered_set<int, HASH> chose;
    f1n(i, n) cin >> a[i];
    last.push_back(n + 1);
    a[n+1] = 400000;
    for(int i = n; i >= 1; i --) {
        update(1, 1, n, i, a[i]);
        if(mp[a[i]] == 0) last.push_back(i);
        mp[a[i]] ++;
        id[a[i]].push_back(i);
    }
    vector<int> res;
    int l = 1, r = last.back();
    int mx_mn = 0;
    while(r <= n) {
        if(mx_mn == 0) {
            auto [x, ix] = query_mx(1, 1, n, l, r);
            res.push_back(x);
            chose.insert(x);
            l = ix + 1;
            while(l > r || chose.count(a[r])) last.pop_back(), r = last.back();
            for(auto i : id[x]) {
                update(1, 1, n, i, INT_MAX);
            }
            mx_mn = 1;
        }
        else {
            auto [x, ix] = query_mn(1, 1, n, l, r);
            res.push_back(x);
            chose.insert(x);
            l = ix + 1;
            while(l > r || chose.count(a[r])) last.pop_back(), r = last.back();
            for(auto i : id[x]) {
                update(1, 1, n, i, INT_MAX);
            }
            mx_mn = 0;
        }
    }
    cout << res.size() << endl;
    for(auto x : res) cout << x << " "; cout << endl;
    // ############################################
    // cout << res << endl;
}

int main(void)
{
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    TEST = 1;
    cin >> TEST;
    while(TEST--)
        solve();
    return 0;
}