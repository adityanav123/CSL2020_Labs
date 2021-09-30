#include <bits/stdc++.h>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        
        return triangle[0][0];
        
}

int main() {
    int n; cin >> n;
    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++) {
        //vector<int> tmp(i+1);
        for(int j = 0; j < i + 1; j++) {
            int t; cin >> t;
            triangle[i].push_back(t);
        }
        //triangle.push_back(tmp);
    }

    cout << minimumTotal(triangle) << "\n";
    return 0;
}
