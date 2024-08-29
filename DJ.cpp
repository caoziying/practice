//
// Created by 21911 on 24-8-29.
//
#include <iostream>
#include <vector>
// 有n(n<=15)个房屋，每个房屋有一个数值x(x>=1且x<=100), 现在要求把n个房屋排成一排，使得相邻的两个房屋的数值a和b满足a整除b或者b整除a，求满足条件的方案数
using namespace std;
int dfs(int i, int mask, vector<int>& a) {
    int n = a.size();
    if(mask == (1 << n) - 1) return 1;
    int res = 0;
    for(int j = 0; j < n; j++) {
        if(!(mask & (1 << j)) && (i == -1 || a[i] % a[j] == 0 || a[j] % a[i] == 0)) {
            res += dfs(j, mask | (1 << j), a);
        }
    }
    // f[i][mask] = res;
    return res;
}
int countArrangements(vector<int>& houses) {
    int n = houses.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));

    // 初始状态：只有一个房屋时的情况
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 1;
    }

    // 状态转移
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int last = 0; last < n; ++last) {
            if (!(mask & (1 << last))) continue;
            for (int next = 0; next < n; ++next) {
                if (mask & (1 << next)) continue;
                if (houses[next] % houses[last] == 0 || houses[last] % houses[next] == 0) {
                    dp[mask | (1 << next)][next] += dp[mask][last];
                }
            }
        }
    }

    // 累加所有满状态的结果
    int totalCount = 0;
    for (int i = 0; i < n; ++i) {
        totalCount += dp[(1 << n) - 1][i];
    }

    return totalCount;
}

int count(vector<int>& a) {
    int n = a.size();
    int res = 0;
    for(int i = 0 ; i < n; i ++) {
        res += dfs(i, 1 << i, a);
    }
    return res;
}
int main() {
    vector<int> houses1 = {1, 4, 5};
    cout << countArrangements(houses1) << endl;  // 输出应为2

    vector<int> houses2 = {1, 3, 9, 27};
    cout << countArrangements(houses2) << endl;  // 输出应为24

    cout << dfs(-1, 0, houses1) << endl;
    cout << dfs(-1, 0, houses2) << endl;
    return 0;
}
