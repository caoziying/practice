//
// Created by 21911 on 24-8-20.
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
unordered_map<PII, int, HASH> qq, clr;
int query(int a, int b) {
    if(qq.contains({a, b})) return qq[{a, b}];
    if(a == b) return a;
//    if(qq.contains({b, a})) {
////        if()
//        return qq[{b, a}] == b ? a : qq[{b, a}];
//    };
    cout << "? " << a << " " << b << endl;
    cout << endl;
    cout.flush();
    int x;
    cin >> x;
    qq[{a, b}] = x;
    return x;
}
vector<int> figure(int a, int m, int b) {
    int x = query(a, m);
    int y = query(m, b);
    if(x == a && y == m) return {a, m, b};
    else {
        auto l = figure(a, x, m);
        auto r = figure(m, y, b);
        for(auto x : r) l.push_back(x);
        return l;
    }
}
void solve()
{
    qq = clr;
    qq.clear();
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // ll res = 0;
    // ########## wirte your code here ###########
    cin >> n;
    unordered_set<PII, HASH> ed;
    unordered_set<int, HASH> vis;
    // 方法1  以1为根，找出每一个结点的父节点
    for(int i = 2; i <= n; i ++) {
        if(vis.count(i)) continue;
        int a = 1, b = i;
        int x = query(b, a);
        while(x != b) {
            a = x;
            x = query(b, a);
        }
        ed.insert({b, a});
    }
    cout << "! ";
    for(auto [l, r] : ed) {
        cout << l << " " << r << " ";
    }
    cout << endl;
    cout << flush;
    return;
    // 找边
    for(int i = 2; i <= n; i ++) {
        if(vis.count(i)) continue;
        int a = 1, b = i;
        int x = query(a, b);
        if(x == a) ed.insert({a, b}), vis.insert(b);
        if(x != a) {
            auto v = figure(a, x, b);
            for(int j = v.size()-1; j > 0; j --) {
                if(v[j] != v[j-1] && ed.count({v[j], v[j-1]}) == 0) ed.insert({v[j-1], v[j]});
//                if(vis.count(v[j])) break;
                vis.insert(v[j]);
            }
        }
        if(ed.size() == n - 1) {
            cout << "!";
            for(auto [l, r] : ed) {
                cout << " " << l << " " << r;
            }
            cout << endl;
            cout << flush;
            return;
        }
    }
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