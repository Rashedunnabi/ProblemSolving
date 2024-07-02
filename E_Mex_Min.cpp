#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k, ans = INT_MAX; cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)    cin >> i;

    map<int,int>mp;
    for (int r = 0; r < k; r++)
        mp[v[r]]++;
    
    for (int mex = 0; mex <= k; mex++)
    {
if (mp.find(mex) == mp.end())
        {
            ans = mex;
            break;
        }
    }

    for (int r = k; r < n; r++) {
mp[v[r]]++;
       mp[v[r-k]]--;
        

        if (v[r] == v[r - k])
            continue;
        
    }

    cout << ans << '\n';

    return 0;
}