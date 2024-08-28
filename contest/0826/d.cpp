//
// Created by 21911 on 24-8-26.
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
const int N = 2e5+15;    //数组长度
//int a[N];
int n, m, k;
// int a, b, c;
// unordered_map<int, int, HASH> mp;
// unordered_map<pair<int, int>, int, HASH> mp2;
int mex[N];
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll res = 0;
    // ########## wirte your code here ###########
    cin >> n >> m;
    vector<PII> vec(n);
    vector<int> val(n);
    vector<int> idx(n);
    int l, x;
    for(int i = 0; i < n; i ++) {
        cin >> l;
        for(int j = 0; j <= l + 10; j ++) mex[j] = 0;
        for(int j = 0; j < l; j ++) {
            cin >> x; if(x <= l + 10) mex[x] = 1;
        }
        bool bu = false;
        int ind = -1, value = -1;
        for(int j = 0; j <= l + 10; j ++) {
            if(mex[j] == 0 && !bu) ind = j, bu = true;
            else if(mex[j] == 0) {
                value = j;
                break;
            }
        }
//        cout << 0 << "-" << ind << " ==> " << value << endl;
//        cout << 0 << "-" << value << " ==> " << value << endl;
//        [0, ind] ==> value
        vec[i] = {0, value};
        val[i] = value;
        idx[i] = i;
    }
    ranges::sort(idx, [&](int i, int j){
//        return vec[i].second < vec[j].second;
            return val[i] > val[j];
    });
    ll res = 0;
    int p = 0;
    for(int i = 0; i < n; i ++) {
        int id = idx[i];
        auto [l, r] = vec[id];
        ll value = val[id];
        if(p > r) continue;
        if(r <= m) {
            res += 1ll * (r - p + 1) * value;
            p = r + 1;
        }
        else {
            res += 1ll * (m - p + 1) * value;
            p = m + 1;
            break;
        }
//        cout << l << " " << r << " " << value << endl;
//        cout << res << endl;
    }
    if(p <= m) res += 1ll * (p + m) * (m - p + 1) / 2;
    // ############################################
    cout << res << endl;
}
//36407041219918287
//365238690095809168
//9223372036854775807
int main(void)
{
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    TEST = 1;
    cin >> TEST;
    while(TEST--)
        solve();
    return 0;
}