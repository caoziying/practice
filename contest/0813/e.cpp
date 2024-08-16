//
// Created by 21911 on 2024/8/14.
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
ll n, m, k;
// int a, b, c;
// unordered_map<int, int, HASH> mp;
// unordered_map<pair<int, int>, int, HASH> mp2;

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll res = 0;
    // ########## wirte your code here ###########
    cin >> n >> m >> k;
    unordered_map<ll, int, HASH> mp;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            ll u = i, d = n - 1 - i, l = j, r = m - 1 - j;
            l = min(k - 1, l), r = min(k - 1, r), u = min(k - 1, u), d = min(k - 1, d);
//            cout << (l + r - k + 2) * (u + d - k + 2) << " ";
            mp[(l + r - k + 2) * (u + d - k + 2)] ++;
        }
//        cout << endl;
    }
    int p;
    cin >> p;
    vector<ll> v(p);
    f0n(i, p) cin >> v[i];
    ranges::sort(v, [&](ll x, ll y){return x > y;});
    int idx = 0;
    vector<PLL> op;
    for(auto [x, cnt] : mp) op.push_back({x, 0ll + cnt});
    ranges::sort(op, [&](auto x, auto y){
        return x.first > y.first;
    });
    for(auto [x, cnt] : op) {
        while(cnt --) {
//            cout << x << "*" << v[idx] << endl;
            res += v[idx ++] * x;
            if(idx == p) break;
        }
        if(idx == p) break;
    }
    // ############################################
    cout << res << endl;
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