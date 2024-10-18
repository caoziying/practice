//
// Created by 21911 on 24-8-31.
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
//struct node{
//    int val;
//    int lazy;
//    node* l, * r;
//    node(): val(0), lazy(0), l(nullptr), r(nullptr) {}
//};
//void update(node* &root, int l, int r, int L, int R, int x) {
//    if(l == L && r == R) {
//        root -> val += x;
//        root -> lazy += x;
//        return;
//    }
//    if(root -> l == nullptr) root -> l = new node();
//    if(root -> r == nullptr) root -> r = new node();
//    if(root -> lazy) {
//        root -> l -> val += root -> lazy;
//        root -> r -> val += root -> lazy;
//        root -> l -> lazy += root -> lazy;
//        root -> r -> lazy += root -> lazy;
//        root -> lazy = 0;
//    }
//    int mid = (l + r) / 2;
//    if(R <= mid) update(root -> l, l, mid, L, R, x);
//    else if(L > mid) update(root -> r, mid + 1, r, L, R, x);
//    else {
//        update(root -> l, l, mid, L, mid, x);
//        update(root -> r, mid + 1, r, mid + 1, R, x);
//    }
//    root -> val = max(root -> l -> val, root -> r -> val);
//}

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll res = 0;
    // ########## wirte your code here ###########
    ll x, mx = 0;
    char op;
    int l, r;
    cin >> n >> m;
    vector<ll> a(n);
    f0n(i, n) cin >> a[i], mx = max(mx, a[i]);
    f0n(i, m) {
        cin >> op >> l >> r;
        if(l <= mx && mx <= r) {
            if(op == '-') mx --;
            else mx ++;
        }
        cout << mx << " ";
    }
    cout << endl;
    // ############################################

}

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