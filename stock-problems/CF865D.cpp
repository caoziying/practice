//
// Created by 21911 on 24-9-29.
//
/*
 * https://www.luogu.com.cn/problem/CF865D
 * https://codeforces.com/problemset/problem/865/D
你可以完美地预测某只股票接下来 N 天的价格，你想利用这一知识盈利，但你每天只想买卖一股
这表明你每天要么什么都不干，要么买入一股，要么卖出一股。起初你没有股票，你也不能在没有股票时卖出股票。
你希望在第 N 天结束时不持有股票，并最大化盈利。
 */
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
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll res = 0;
    // ########## wirte your code here ###########
    cin >> n;
    vector<int> a(n);
    f0n(i, n) cin >> a[i];
    priority_queue<int, vector<int>, greater<>> q;
    ll res = 0;
    f0n(i, n) {
        if(!q.empty() && q.top() < a[i]) {
            res += a[i] - q.top();
            q.pop();
            q.push(a[i]);
        }
        else
            q.push(a[i]);   // 反悔之后，还可以选择这个中间物
    }
    cout << res << endl;
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
//    cin >> TEST;
    while(TEST--)
        solve();
    return 0;
}