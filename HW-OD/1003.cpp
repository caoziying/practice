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
//    string str = "   I  am     a             dev    ", tmp;
//    stringstream ss(str);
//    while(ss>>tmp) {
//        cout << "_" << tmp << "_" << endl;
//    }
    string str = "ferg(3,10)sadfa(10,10)(123,400)asdfasdf";
//    cin >> str;
    int p = 0;
    while(str.find('(',p) != string::npos) {
        int p0 = str.find('(', p);
        int p1 = str.find(',', p);
        int p2 = str.find(')', p);
        int a = atoi(str.substr(p0 + 1, p1 - p0 - 1).c_str());
        int b = atoi(str.substr(p1 + 1, p2 - p1 - 1).c_str());
        cout << a << " " << b << endl;
        p = p2 + 1;
    }
//    ss << "12123111111113";
//    cout << ss.str();
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