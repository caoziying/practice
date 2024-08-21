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

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // ll res = 0;
    // ########## wirte your code here ###########
    cin >> n;
    if(n % 2== 0) cout << -1 <<endl;
    else {
        vector<int> a(n);
        int mid = n / 2;
        int l = 1;
        a[mid] = 1;
        int x = 1;
        while(l <= n/2) {
            a[mid+l] = ++ x;
            a[mid-l] = ++ x;
            l ++;
        }
        for(int i = 0; i < n; i ++) cout << a[i] << " "; cout << endl;
    }
//    vector<int> v = {0, 3, 1, 2, 4};
//    int t1 = 0, t2 = 0;
//    int k = 1;
//    for(int i = 1; i <= 4; i ++) {
//        bool f = false;
//        for(int j = k; j <= 4; j ++) {
//            if(v[j] == i) f = true, t1 += j - k + 1, k = j;
//        }
//        if(!f) {
//            t1 ++;
//            k = 1;
//            for(int j = k; j <= 4; j ++) {
//                if(v[j] == i) t1 += j - k + 1, k = j;
//            }
//        }
//    }
////    cout << t1 << endl;
//    n = v.size();
//    k = 4;
//    for(int i = 1; i <= 4; i ++) {
//        bool f = false;
//        for(int j = k; j >= 1; j --) {
//            if(v[j] == i) {
//                f = true, t2 += k - j + 1, k = j;
//            }
//        }
//        if(!f) {
//            t2 ++;
//            k = 4;
//            for(int j = k; j >= 1; j --) {
//                if(v[j] == i) t2 += k - j + 1, k = j;
//            }
//        }
////        cout << t2 << " ";
//    }
//    cout << t1 << " " << t2 << endl;
    // ############################################
    // cout << res << endl;
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