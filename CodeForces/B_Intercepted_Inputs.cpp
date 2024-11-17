#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int k, i;
        cin >> k;

        map<int, int> mp;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        int sz = k - 2;
        int n = -1, m = -1;
        for (auto p : mp)
        {
            if (sz % p.first == 0)
            {
                int nxtsz = sz / p.first;
                if (mp.find(nxtsz) != mp.end())
                {
                    if (nxtsz == p.first)
                    {
                        if (mp[nxtsz] > 1)
                        {
                            n = p.first;
                            m = p.first;
                            break;
                        }
                    }
                    else
                    {
                        n = p.first;
                        m = nxtsz;
                    }
                }
            }
        }
        cout << n << ' ' << m << '\n';
    }
    return 0;
}