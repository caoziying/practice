//
// Created by 21911 on 2024/8/13.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <chrono>

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
//int n, m;
// int a, b, c;
// unordered_map<int, int, HASH> mp;
// unordered_map<pair<int, int>, int, HASH> mp2;

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // ########## wirte your code here ###########
    string str;
    cin >> str;
    stack<int> sta;
    int n = (int)str.size();
    vector<int> ans(n + 1, 0);
    int res1 = 0, res2 = 1;
    str = "#" + str;
    for(int i = 1; i <= n; i ++) {
        /*
         * 遇到 ')'，判断以 左边相邻位置结束的最长正则括号序列 的左边相邻位置是否为 '('，是则可以匹配，更新答案
         * 例子：(()())(())
         * 遍历到最后一位 第 10 位，查询 对应第 7(10 - ans[9] - 1) 位 是否为 '('，是，则更新为
         * ans[i-1] + 2 + ans[i - ans[i-1] - 2]
         * 即 2 + 2 + 6
         * */
        if(str[i] == ')') {
            ans[i] = (str[i-ans[i-1]-1] == '(' ? ans[i-1] + 2 + ans[i-2-ans[i-1]] : 0);
//            if(str[i-1] == '(') ans[i] = 2 + ans[i-2];
//            else ans[i] = (str[i-ans[i-1]-1] == '(' ? ans[i-1] + 2 + ans[i-2-ans[i-1]] : 0);
        }
        if(ans[i] > res1) res1 = ans[i], res2 = 0;
        if(ans[i] == res1) res2 ++;
    }
    if(res1 == 0) res2 = 1;
    cout << res1 << " " << res2 << endl;
//    for(int i = 1; i <= n; i ++) {
//        if(ans[i])
//            cout << i - ans[i] + 1 << " " << i << endl;
//    }
}


int main(void)
{
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    TEST = 1;
//    cin >> TEST;
    while(TEST--)
        solve();
    return 0;
}