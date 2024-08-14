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
    int x;
    set<int> s = {0, 10000000};
    set<PII> q;
    vector<int> arr;
    f0n(i, n) { cin >> x; s.insert(x); }
    for(int val : s) arr.push_back(val);
    f0n(i, n + 1) {
        q.insert({arr[i + 1] - arr[i] - 1, arr[i] + 1});
    }
    cin >> m;
    while(m --) {
        char op;
        int val;
        cin >> op >> val;
        if(op == '+') {
            auto it = s.lower_bound(val);
            auto bef = prev(it);
            q.erase({*it - *bef - 1, *bef + 1});
            q.insert({val - *bef - 1, *bef + 1});
            q.insert({*it - val - 1, val + 1});
            s.insert(val);
        }
        else if(op == '-') {
            auto it = s.lower_bound(val);
            auto nx = next(it);
            auto bef = prev(it);
            q.erase({*it - *bef - 1, *bef + 1});
            q.erase({*nx - *it - 1, *it + 1});
            q.insert({*nx - *bef - 1, *bef + 1});
            s.erase(it);
        }
        else {
            auto it = q.lower_bound({val, -1});
            cout << (*it).second << " ";
        }
    }
    cout << endl;
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