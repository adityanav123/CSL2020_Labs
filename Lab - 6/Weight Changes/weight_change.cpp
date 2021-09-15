#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> solve(vector<int> v) {
    vector<pair<int,int>> pos;
    for(int i = 0; i < v.size(); i++) {
        pos.push_back(make_pair(v[i], i));
    }

    sort(pos.begin(), pos.end());
    vector<int> ans;
    for(int i = 0; i < pos.size(); i++) {
        ans.push_back(pos[i].second);
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    #endif
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> ans = solve(v);
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
