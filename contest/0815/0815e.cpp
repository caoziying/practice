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
const int N = 1e7+5;    //数组长度
//int a[N];
int n, m, k;
// int a, b, c;
// unordered_map<int, int, HASH> mp;
// unordered_map<pair<int, int>, int, HASH> mp2;
// 辅助函数：检查一个数是否为质数
int SG[N];
vector<int> prime;
vector<int> st, minp;
void eular(int n) {
    st.resize(n+1, false);
    minp.resize(n+1, 0);
    for(int i = 2; i <= n; i++) {
        // cout << i << endl;
        if(!st[i]) { minp[i] = i, prime.push_back(i); }
        for(int j = 0; prime[j] <= n / i; j++) {
            st[i*prime[j]] = true;
            minp[i*prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // ll res = 0;
    // ########## wirte your code here ###########
    cin >> n;
    vector<int> a(n);
    int res = 0;
    f0n(i, n) cin >> a[i], res ^= SG[a[i]];
    if(res == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    // ############################################
    // cout << res << endl;
}
// 打表发现 sg 函数为最小质因子在质因子表中的 下标+1
int f[101];
int sg(int x) {
    if(f[x]) return f[x];
    set<int> t;
    for(int i = 1; i <= x; i ++) {
        if(gcd(x, i) == 1) t.insert(sg(x - i));
    }
    for(int i = 0; ; i ++) {
        if(t.count(i) == 0) return f[x] = i;
    }
}
int main(void)
{
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    TEST = 1;
    eular(N);
    memset(SG, 0, sizeof SG);
    SG[1] = 1;
    for(int i = 0; i < 100; i ++) cout << prime[i] << " "; cout << endl;
    for(int i = 0; i < prime.size(); i ++) SG[prime[i]] = i + 1;
    for(int i = 3; i <= N; i += 2) SG[i] = SG[minp[i]];

    for(int i = 0; i < 101; i ++) cout << SG[i] << " " << sg(i) << endl;
//    cin >> TEST;
//    while(TEST--)
//        solve();
    return 0;
}