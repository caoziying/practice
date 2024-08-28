//
// Created by 21911 on 24-8-28.
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
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll res = 0;
    // ########## wirte your code here ###########
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1, -1);
    vector<array<int, 3>> query(m);
    vector<int> res(m, -1);
    f1n(i, n) cin >> a[i];
    f0n(i, m) cin >> query[i][0] >> query[i][1] >> query[i][2];
//    unordered_map<int, vector<int>, HASH> mp;
//    f1n(i, n) mp[a[i]].push_back(i);
//    f0n(k, m) {
//        int L = query[k][0], R = query[k][1], x = query[k][2];
//        if(!mp.contains(x)) {
//            res[k] = L;
//            continue;
//        }
//        int l = 0, r = mp[x].size() - 1;
//        while(l < r) {
//            int mid = (l + r) / 2;
//            if(mp[x][mid] >= L) r = mid;
//            else l = mid + 1;
//        }
//        int ll = l;
//        l = 0, r = mp[x].size() - 1;
//        while(l < r) {
//            int mid = (l + r + 1) / 2;
//            if(mp[x][mid] <= R) l = mid;
//            else r = mid - 1;
//        }
//        int rr = l;
//        if(mp[x][ll] > L) res[k] = L;
//        else if(mp[x][rr] < R) res[k] = R;
//        else if(rr - ll != R - L) {
//            int i = ll, j = rr;
//            while(i < j) {
//                int mid = (i + j) / 2;
//                if(mid - i == mp[x][mid] - mp[x][i]) i = mid + 1;
//                else j = mid;
//            }
//            res[k] = mp[x][i] - 1;
//        }
//    }
    for(int i = 2; i <= n; i ++) {
        if(a[i] != a[i-1]) b[i] = i - 1;
        else b[i] = b[i - 1];
    }
    f0n(i, m) {
        int l = query[i][0], r = query[i][1], x = query[i][2];
        if(a[r] != x) res[i] = r;
        else res[i] = b[r] >= l ? b[r] : -1;
    }
    f0n(i, m) cout << res[i] << endl;
    // ############################################
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