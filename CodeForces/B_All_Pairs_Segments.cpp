#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, q, i;
        cin >> n >> q;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int right = n - i - 1;
            int left = (n - i) * i;
            int val = left + right;
            mp[val]++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int dif = v[i + 1] - v[i];
            if (dif > 1)
            {
                int val = (i + 1) * (n - i - 1);
                mp[val] += dif - 1;
            }
        }
        while (q--)
        {
            int x;
            cin >> x;
            if (mp.find(x) == mp.end())
                cout << 0 << ' ';
            else
                cout << mp[x] << ' ';
        }
        cout << '\n';
    }
    return 0;
}