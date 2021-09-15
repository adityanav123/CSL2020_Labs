#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <climits>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    #endif
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    unordered_map<int, int> count;

    for(auto x : v) {
        if(count.find(x) == count.end())
            count[x] = 1;
        else ++count[x];
    }
    int target = floor(n / 2);
    int ans = -1;
    for(auto x : v) {
        if(count[x] > target) {
            ans = x; break;
        }
    }
    cout << ans << "\n";
    return 0;
}
