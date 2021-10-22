#include <bits/stdc++.h>
using namespace std;
int i = 0;
    string solve(string s) {
        string op = "";
        int val = 0;
        
        while(i < s.length()) {
            if(isdigit(s[i])) {
                //cout << "digit! - " << s[i] << "\n";
                val = ((10 * val) + (s[i] - '0'));
                //cout << "s[i] - '0'" << s[i] - '0 : ' << "\n";
                //cout << "val - " << val << "\n";
            }    
            else if(s[i] == '[') {
                i++;
                string tmp = solve(s);
                //cout << "val - " << val << "\n";
                for (int j = 0; j < val; j++) {
                    op += tmp;
                }
                val = 0;
            }
            else if(s[i] == ']') return op;
            else op.push_back(s[i]);
            i++;
        }
        return op;
    }

int main() {
    string s; cin >> s;
    cout << solve(s);
    return 0;
}
