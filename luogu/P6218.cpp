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
int n, m, k;
ll mod = 1e9 + 7;
// int a, b, c;
// unordered_map<int, int, HASH> mp;
// unordered_map<pair<int, int>, int, HASH> mp2;
string low = "", high = "";
vector<vector<vector<ll>>> f;
int dfs(int i, int st, int cnt, int isLow, int isHigh) {
    if(i == n) {
        if(st == -1) return 0;
        return cnt >= (n - st + 1) / 2;
    }
    if(st != -1 && !isLow && !isHigh && f[i][st][cnt] != -1) return f[i][st][cnt]; 
    int l = isLow ? low[i] - '0' : 0;
    int r = isHigh ? high[i] - '0' : 1;
    ll res = 0;
    for(int d = l; d <= r; d ++) {
        if(d == 0) {
            if(st == -1) res += dfs(i + 1, st, cnt, isLow && (d + '0' == low[i]), isHigh && (d + '0' == high[i]));
            else res += dfs(i + 1, st, cnt + 1, isLow && (d + '0' == low[i]), isHigh && (d + '0' == high[i]));
        }
        else {
            if(st == -1) res += dfs(i + 1, i, cnt, isLow && (d + '0' == low[i]), isHigh && (d + '0' == high[i]));
            else res += dfs(i + 1, st, cnt, isLow && (d + '0' == low[i]), isHigh && (d + '0' == high[i]));
        }
    }
    if(st != -1 && !isLow && !isHigh) f[i][st][cnt] = res;
    return res;
}
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll res = 0;
    // ########## wirte your code here ###########
    int L, R;
    cin >> L >> R;
    high = "", low = "";
    while(R) high.push_back((R % 2) + '0'), R /= 2;
    while(L) low.push_back((L % 2) + '0'), L /= 2;
    n = high.size();
    ranges::reverse(high);
    ranges::reverse(low);
    low = string(n - low.size(), '0') + low;
    f.resize(n, vector<vector<ll>>(31, vector<ll>(31, -1)));
    // cout << low << endl << high << endl;
    cout << dfs(0, -1, 0, 1, 1) << endl;
    // ############################################
    // cout << res << endl;
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