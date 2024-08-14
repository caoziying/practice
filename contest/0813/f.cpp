//
// Created by 21911 on 24-8-14.
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

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cnt = 0;
    // ########## wirte your code here ###########
    cin >> n >> k;
    vector<vector<int>> cost(n);
    f0n(i, n) {
        int x, y;
        cin >> x >> y;
        cnt += x + y;
        cost[i].push_back(0);
        for(; x && y; ) {
            cost[i].push_back(min(x, y));
            if(x > y) x -= 1;
            else y -= 1;
        }
        cost[i].push_back(0);
        for(int j = 1; j < (int)cost[i].size(); j ++) cost[i][j] += cost[i][j-1];
//        for(auto w : cost[i]) cout << w << " "; cout << endl;
    }
    if(cnt < k) { cout << -1 << endl; return; }
    vector<int> f(k + 1, INT_MAX / 2);
    f[0] = 0;
    // 分组背包
    /*
     * f[i][j] = min(f[i-1][j], f[i-1][j-v0], ..., f[i-1][j-vi], ...)
     * 大的 j 依赖小的 j，从大到小遍历
     */
    for(int i = 0; i < n; i ++) {
        for(int t = k; t >= 0; t --)
            for(int j = 0; j < cost[i].size(); j ++)
                if(t >= j) f[t] = min(f[t], f[t - j] + cost[i][j]);
    }
    // ############################################
//    for(auto x : f) cout << x << " "; cout << endl;
     cout << f[k] << endl;
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