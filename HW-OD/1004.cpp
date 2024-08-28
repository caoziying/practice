//
// Created by 21911 on 24-8-21.
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
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll res = 0;
    // ########## wirte your code here ###########
    vector<string> str(60, "");
    str[0] = "1";
    for(int i = 1; i < 60; i ++) {
        auto& s = str[i-1];
        int n = (int)s.size();
        char ch = s[0];
        int cnt = 1;
        str[i] = "";
        for(int j = 1; j < n; j ++) {
            if(s[j] == ch) cnt ++;
            else {
                str[i] += to_string(cnt);
                str[i].push_back(ch);
                ch = s[j];
                cnt = 1;
            }
        }
        str[i] += to_string(cnt);
        str[i].push_back(ch);
//        cout << str[i] << endl;
    }
    cout << str[59].size() << endl;
    for(int i = 0; i < 10; i ++) cout << str[i] << endl;
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
    double start = clock();
    while(TEST--)
        solve();
    double end = clock();
    double last = end - start;
    cout << last << "ms" << endl;
    return 0;
}