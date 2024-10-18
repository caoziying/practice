//
// Created by 21911 on 24-10-8.
//
#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, vector<int>& b) {
    set<int> st;
    int cnt = 0;
    for(auto& x : a) {
        st.insert(x);
        auto it = st.lower_bound(x);
        auto p = prev(it);
        auto q = next(it);
        if(it == st.begin()) {
            if(q == st.end() || (q != st.end() && (*q) != (*it) + 1)) cnt ++;
        }
        else {
            if(q == st.end()) {
                if((*p) != (*it) - 1) cnt ++;
            }
            else {
                if((*p) == (*it) - 1 && (*q) == (*it) + 1) cnt --;
                else if((*p) == (*it) - 1 || (*q) == (*it) + 1) ;
                else cnt ++;
            }
        }
    }
    for(auto& x : b) {
        auto it = st.lower_bound(x);
        auto p = prev(it);
        auto q = next(it);
        if(it == st.begin()) {
            if(q == st.end() || (q != st.end() && (*q) != (*it) + 1)) cnt --;
        }
        else {
            if(q == st.end()) {
                if((*p) == (*it) - 1) ;
                else cnt --;
            }
            else {
                if((*p) == (*it) - 1 && (*q) == (*it) + 1) cnt ++;
                else if((*p) == (*it) - 1 || (*q) == (*it) + 1) ;
                else cnt --;
            }
        }
        st.erase(it);
        cout << cnt << " ";
    }
}
int main(void) {
    vector<int> houses = {1, 2, 3, 6, 7, 9};
    vector<int> ops = {6, 3, 7, 2, 9, 1};
    solve(houses, ops);
}