#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int j = 0, ans = 0;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;

        int dif = mp.rbegin()->first - mp.begin()->first;

        while (dif > k)
        {
            mp[v[j]]--;
            if (mp[v[j]] == 0)
            {
                mp.erase(mp.find(v[j]));
            }
            dif = mp.rbegin()->first - mp.begin()->first;
            j++;
        }
        ans += i - j + 1;
    }

    cout << ans << '\n';

    return 0;
}
