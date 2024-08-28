//
// Created by 21911 on 24-8-26.
//
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
//struct node {
//    int val;
//    int lazy;
//    ll x;
//    node* l, *r;
//    node(): val(0),lazy(0),x(0),l(nullptr),r(nullptr) {}
//};
//void update(node* &root, int l, int r, int L, int R) {
//    if(l == L && r == R) {
//        root->val = r - l + 1;
//        root->lazy = 1;
//        root->x = 1ll * (l + r-2) * (r - l + 1) / 2;
//        return;
//    }
//    int mid = (l + r) / 2;
//    if(root->l == nullptr) root->l = new node();
//    if(root->r == nullptr) root->r = new node();
//    if(root->lazy) {
//        root->l->val = mid - l + 1;
//        root->l->lazy = 1;
//        root->l->x = 1ll * (l + mid-2) * (mid - l + 1) / 2;
//        root->r->val = r - mid;
//        root->r->lazy = 1;
//        root->r->x = 1ll * (mid+1 + r-2) * (r - mid) / 2;
//        root->lazy = 0;
//    }
//    if(R <= mid) update(root->l, l, mid, L, R);
//    else if(L > mid) update(root->r, mid + 1, r, L, R);
//    else {
//        update(root->l, l, mid, L, mid);
//        update(root->r, mid + 1, r, mid + 1, R);
//    }
//    root->x = root->l->x + root->r->x;
//    root->val = root->l->val + root->r->val;
//}
//int query(node* &root, int l, int r, int L, int R) {
////    cout << l << " " << r << " " << L << " " << R<< endl;
////    return 0;
//    if(l == L && r == R) return root->val;
//    int mid = (l + r) / 2;
//    if(root->l == nullptr) root->l = new node();
//    if(root->r == nullptr) root->r = new node();
//    if(root->lazy) {
//        root->l->val = mid - l + 1;
//        root->l->lazy = 1;
//        root->l->x = 1ll * (l + mid-2) * (mid - l + 1) / 2;
//        root->r->val = r - mid;
//        root->r->lazy = 1;
//        root->r->x = 1ll * (mid+1 + r-2) * (r - mid) / 2;
//        root->lazy = 0;
//    }
//    if(R <= mid) return query(root->l, l, mid, L, R);
//    else if(L > mid) return query(root->r, mid + 1, r, L, R);
//    else {
//        return query(root->l, l, mid, L, mid) +
//        query(root->r, mid + 1, r, mid + 1, R);
//    }
//}
vector<vector<int>> e;
vector<int> memo;
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll res = 0;
    e.resize(N);
    // ########## wirte your code here ###########
    vector<int> in(N, 0), out(N, 0);
    vector<PII> ed;
    cin >> n >> m;
    int mx = 0, mxval = 0;
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
        mx = max(mx, value);
        mxval = max(mxval, ind);
        ed.push_back({ind, value});
        // 一系列 u -> v 的边
    }
    // dp[x] 表示 x 通过所有 u->v 的边可以到达的最大值
    // x 可以取到所有的 u，但是选取 u 之后，与其相连的某一条 v 的边需要舍弃（相当于操作一次，不能重复操作了）
    // 某个 u 的出度大于1时，舍弃一条边后，我们可以选择另一条边继续走，且我们可以舍弃任意一条边，也就意味着我们仍然可以取到 dp[u]
    vector<int> dp(mx + 1, 0);
    for(int i = 0; i <= mx; i ++) e[i].clear();
    for(auto [l, r] : ed) {
        e[r].push_back(l);
        in[l] ++; // 逆序思考
        out[l] ++;    // 正序思考
    }
    queue<int> q;
    for(int i = 0; i <= mx; i ++) if(in[i] == 0) q.push(i);
    while(q.size()) {
        auto t = q.front();
        q.pop();
        dp[t] = max(dp[t], t);
        for(auto x : e[t]) {
            dp[x] = max(dp[x], dp[t]);
            in[x] --;
            if(in[x] == 0) q.push(x);
        }
    }
    for(int i = 0; i <= mx; i ++) {
        if(out[i] > 1) mxval = max(mxval, dp[i]);
    }
    ll res = 0;
    for(int i = 0; i <= min(mxval, m); i ++) {
//        cout << max(mxval, dp[i]) << endl;
        res += max(mxval, dp[i]);
    }
    int o = min(mxval, m) + 1;
    res += 1ll * (m - o + 1) * (m + o) / 2;
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