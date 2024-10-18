//
// Created by 21911 on 24-9-10.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int n = str.size();
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int sum = 0;
    for(auto ch : str) sum += (ch == 'I');
    if(sum == n) {
        cout << 0 << endl;
        return 0;
    }
    if(str == "M" || str == "MM") {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n - 2; i ++) {
        if(str[i] == 'M' && str[i+1] == 'M' && str[i+2] == 'M') {
            cout << -1 << endl;
            return 0;
        }
    }
    if(str.substr(0, 2) == "MM" || str.substr(n-2) == "MM") {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= n-3; i ++) {
        if(str[i] == 'M' && str[i+1] == 'M') {
            str[i-1] = 'F';
            str[i+2] = 'F';
        }
    }
    string tmp = "#" + str + "#";
    str = tmp;
    n = str.size() - 2;
    for(int i = 1; i <= n; i ++) {
        if(str[i] == 'M' && i == n) {
            if(str[i-1] == 'F') continue;
            str[i-1] = 'F';
        }
        else if(str[i] == 'M') {
            if(i - 1 >= 0 && str[i-1] == 'F' || i + 1 <= n && str[i+1] == 'F') continue;
            if(i + 1 <= n) str[i+1] = 'F';
        }
    }
    int res = 0;
    for(auto ch : str) res += (ch == 'F');
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")