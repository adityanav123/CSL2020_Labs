#include <bits/stdc++.h>
using namespace std;

int dp[300];
    
    bool helper(string s, vector<string>& w)
    {
        if(s.size() == 0) return dp[s.size()] = true;
        if(dp[s.size()] != -1) return dp[s.size()];
            
        bool check = false;
        
        for(int idx = 0; idx < w.size(); idx++)
        {
            if(s.substr(0, w[idx].size()) == w[idx])
            {
                if(helper(s.substr(w[idx].size()), w)) 
                {
                    check = true;
                    break;
                }
            }
        }
        
        return dp[s.size()] = check;
    }
    
    bool wordBreak(string s, vector<string>& W)
    {
        if(W.size() == 0) return false;
        
        memset(dp, -1, sizeof dp);
        
        return helper(s, W);
    }
int main() {
    string s; cin >> s;
    int n; cin >> n;
    vector<string> word(n);
    for(int i = 0; i < n; i++) cin >> word[i];
    if(wordBreak(s, word) == true) cout << "true\n";
    else cout << "false\n";
    return 0;
}
