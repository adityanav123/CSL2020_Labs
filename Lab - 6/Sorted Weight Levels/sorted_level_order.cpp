#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

void levelorder(vector<int> v, int levelno, int curridx, vector<vector<int>> &level) {
    // initally curridx is 0.
    while(curridx < v.size()) {
        int values_in_curr_level = (pow(2, levelno));
        vector<int> currLevel;
        int lastbound = values_in_curr_level;

        if(curridx + values_in_curr_level >= v.size()) lastbound = v.size() - curridx;
        for(int i = 0; i < lastbound; i++) {
            currLevel.push_back(v[curridx + i]);
        }
        level.push_back(currLevel);
        levelno++;
        curridx += values_in_curr_level;
    }
}

void solve(vector<int> v) {
    vector<vector<int>> level;
    levelorder(v, 0, 0, level);

    for(auto x : level) {
        sort(x.begin(), x.end());
        for(auto y : x) {
            cout << y << " ";
        }cout << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    #endif
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    solve(v);
    return 0;
}
