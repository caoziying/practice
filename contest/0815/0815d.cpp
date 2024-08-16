//
// Created by 21911 on 24-8-15.
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
int n, q;
// int a, b, c;
// unordered_map<int, int, HASH> mp;
// unordered_map<pair<int, int>, int, HASH> mp2;

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // ll res = 0;
    // ########## wirte your code here ###########
    cin >> n >> q;
    string str;
    unordered_map<string, vector<int>, HASH> pt, clr1;
    unordered_map<int, string, HASH> toP, clr2;
    pt = clr1, toP = clr2;
    vector<string> vec = {"BG", "BR", "BY", "GR", "GY", "RY"};
    for(auto s : vec) pt[s] = {};
    f1n(i, n) {
        cin >> str;
        pt[str].push_back(i);
        toP[i] = str;
    }
    for(auto& [x, v] : pt) {
        sort(pt[x].begin(), pt[x].end());
    }

    while(q--) {
        int res = INT_MAX;
        int x, y;
        cin >> x >> y;
        string p1 = toP[x], p2 = toP[y];
        if(p1[0] == p2[0] || p1[0] == p2[1] || p1[1] == p2[0] || p1[1] == p2[1]) {
            cout << abs(x - y) << endl;
        }
        else {
            int l = min(x, y), r = max(x, y);
            for(auto s : vec) {
                if(s == p1 || s == p2) continue;
                auto v = pt[s];
                if(v.size() == 0) continue;
                if(v[0] >= r) res = min(res, 2 * v[0] - r - l);
                else if(v.back() <= l) res = min(res, l + r - 2 * v.back());
                else {
                    int i = 0, j = v.size() - 1;
                    while(i < j) {
                        int mid = (i + j) / 2;
                        if(v[mid] >= l) j = mid;
                        else i = mid + 1;
                    }
                    res = min(res, abs(v[i] - l) + abs(v[i] - r));
                    if(i - 1 >= 0)
                        res = min(res, abs(v[i-1] - l) + abs(v[i-1] - r));
                    i = 0, j = v.size() - 1;
                    while(i < j) {
                        int mid = (i + j) / 2;
                        if(v[mid] >= r) j = mid;
                        else i = mid + 1;
                    }
                    res = min(res, abs(v[i] - l) + abs(v[i] - r));
                    if(i - 1 >= 0)
                        res = min(res, abs(v[i-1] - l) + abs(v[i-1] - r));
                }
            }
            cout << (res == INT_MAX ? -1 : res) << endl;
        }
    }
    // ############################################
}

int main(void)
{
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    TEST = 1;
    cin >> TEST;
    while(TEST--)
        solve();
    return 0;
}