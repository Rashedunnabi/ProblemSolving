#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    map<int, int> mp;
    int l = 0, r = 0, left = -1, right = -1, maxi = 0, cnt = 0;
    while (r < n)
    {
        if (mp[v[r]] == 0)
            cnt++;
        mp[v[r]]++;
        while (cnt > k)
        {
            mp[v[l]]--;
            if (mp[v[l]] == 0)
                cnt--;
            l++;
        }
        if (r - l + 1 > maxi)
        {
            maxi = r - l + 1;
            left = l, right = r;
        }
        r++;
    }
    cout << left + 1 << ' ' << right + 1 << '\n';
    return 0;
}