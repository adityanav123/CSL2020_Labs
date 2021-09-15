#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
vector<int> getStrongest(vector<int>& arr, int k) 
    {
        int n = arr.size();
        long int i = 0, j = n-1;
        sort(arr.begin(),arr.end());
        int mid = arr[((n-1)/2)];
        vector<long int> ans;
        while(i < j)
        {
            if(abs(arr[i]-mid) > abs(arr[j]-mid))
            {
                ans.push_back(arr[i++]);
            }
            else if(abs(arr[i]-mid) == abs(arr[j]-mid) && arr[i] > arr[j])
            {
                ans.push_back(arr[i++]);
            }
            else if(abs(arr[i]-mid) == abs(arr[j]-mid) && arr[i] < arr[j])
            {
                ans.push_back(arr[j--]);
            }
            else if(abs(arr[i]-mid) == abs(arr[j]-mid))
            {
                ans.push_back(arr[j--]);
            }
            else if(abs(arr[i]-mid) < abs(arr[j]-mid))
            {
                ans.push_back(arr[j--]);
            }
        }
        ans.push_back(mid);
        i = 0;
        vector<int> fin;
        while(k--)
        {
            fin.push_back(ans[i++]);
        }
        return fin;
    } 

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin); 
    #endif
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int k; cin >> k;
    vector<int> ans = getStrongest(v, k);
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
