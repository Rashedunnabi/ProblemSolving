#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        map<int, int> mp;
        for (int i : v)
            mp[i]++;
        int maxi = 0;
        for (auto val : mp)
            maxi = max(maxi, val.second);
        cout << n - maxi << '\n';
    }
    return 0;
}