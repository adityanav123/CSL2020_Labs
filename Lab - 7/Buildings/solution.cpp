#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<int>> m;
        for(auto &b : buildings) {
            m[b[0]].push_back(b[2]);
            m[b[1]].push_back(-b[2]);
        }
        
        vector<vector<int>> res;
            
        map<int, int> h;
        int cur_h = 0;
        for(auto &p : m)
        {
            int rh = 0;
            for(int ph : p.second) {
                if(ph < 0) {
                    if(--h[-ph] == 0)
                        h.erase(-ph);
                } else {
                    ++h[ph];
                    rh = max(rh, ph);
                }
            }
            if(rh > cur_h) {
                cur_h = rh;
                res.push_back( {p.first, cur_h} );
            } else if(h.count(cur_h) == 0) {
                cur_h = h.empty() ? 0 : h.rbegin()->first;
                res.push_back( {p.first, cur_h} );
            }
        }
         
        return res;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> buildings(N, vector<int>(3));
    for(int i = 0; i < N; i++) {
        //vector<int> parameters(3);
       // cin >> parameters[0] >> parameters[1] >> parameters[2];
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];
        //buildings.push_back(parameters);
    }
    /*cout << "input : \n";
    for(auto x : buildings) {
        cout << x[0] << " " << x[1] << " " << x[2] << "\n";
    }*/

    vector<vector<int>> answer = getSkyline(buildings);
    //cout << "calculated!\n";

    for(auto x : answer) {
        cout << x[0] << " " << x[1] << "\n";
    }
}
