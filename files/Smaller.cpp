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
int n, m;
// int a, b, c;
// unordered_map<int, int, HASH> mp;
// unordered_map<pair<int, int>, int, HASH> mp2;

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // ########## wirte your code here ###########
    cin >> n;
    int op, k;
    string str;
    vector<ll> a(26, 0), b(26, 0), suf(27, 0), pre(27, 0);
    a[0] = 1, b[0] = 1;
    f0n(i, n) {
        cin >> op >> k >> str;
        if(op == 1) for(auto ch : str) a[ch - 'a'] += k;
        else for(auto ch : str) b[ch - 'a'] += k;
        for(int j = 25; j >= 0; j --) suf[j] = suf[j + 1] + a[j];
        for(int j = 0; j <= 25; j ++) pre[j + 1] = pre[j] + b[j];
        int ida = -1, idb = -1;
        f0n(j, 26) if(a[j]) { ida = j; break; }
        for(int j = 25; j >= 0; j --) if(b[j]) { idb = j; break; }
        if(ida == idb && (a[ida] >= b[idb] && pre[idb] == 0 || a[ida] <= b[idb] && suf[ida+1])) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    // ############################################
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