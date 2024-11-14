//
// Created by NK on 24-11-14.
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
ll mod = 10000007;
ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll res = 0;
    // ########## wirte your code here ###########
    ll R;
    cin >> R;
    string high = "";
    while(R) high.push_back((R % 2) + '0'), R /= 2;
    ranges::reverse(high.begin(), high.end());
    // cout << high <<endl;
    n = high.size();
    // vector<PII> f(n + 1, {-1, -1});
    vector<vector<ll>> f(n + 1, vector<ll>(n + 1, -1));
    auto dfs = [&](auto&& dfs, int i, int num, int isHigh, int isZero) -> ll {
        if(i == n) return num == 0 ? 1ll : 0ll;
        if(num < 0) return 0ll;
        if(!isHigh && !isZero && ~f[i][num]) return f[i][num];
        int r = isHigh ? high[i] - '0' : 1;
        ll res = 0;
        for(int d = 0; d <= r; d ++) {
            res += dfs(dfs, i + 1, num - d, isHigh && d == (high[i] - '0'), isZero && d == 0);
        }
        // res %= mod;
        if(!isHigh && !isZero) f[i][num] = res;
        return res;
    };
    vector<ll> cnt(n + 1, 0);
    for(int i = 1; i <= n; i++) cnt[i] = dfs(dfs, 0, i, 1, 1);
    ll res = 1;
    for(int i = 2; i <= n; i++) {
        // cout << cnt[i] << " ";
        res = res * qmi(i, cnt[i]) % mod;
    }
    cout << res << endl;
    // auto dfs = [&](auto&& dfs, int i, int isHigh, int isZero) -> PII {
    //     if(i == n) return {0, 1};
    //     if(!isHigh && !isHigh && ~f[i].first) return f[i];
    //     int r = isHigh ? high[i] - '0' : 1;
    //     ll resnum = 0, ressum = 0;
    //     for(int d = 0; d <= r; d ++) {
    //         if(isZero && d == 0) {
    //             auto [sum, num] = dfs(dfs, i + 1, isHigh && d == high[i] - '0', true);
    //             ressum += sum;
    //             resnum += num;
    //         }
    //         else {
    //             auto [sum, num] = dfs(dfs, i + 1, isHigh && d == high[i] - '0', false);
    //             if(d == 1) ressum += num;
    //             ressum += sum;
    //             resnum += num;
    //         }
    //         resnum %= mod;
    //         ressum %= mod;
    //     }
    //     if(!isHigh && !isHigh) f[i] = {ressum, resnum};
    //     return {ressum, ressum};
    // };
    // // ############################################
    //
    // cout << dfs(dfs, 0, 1, 1).first << endl;
}

int main(void)
{
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    TEST = 1;
    // cin >> TEST;
    while(TEST--)
        solve();
    return 0;
}