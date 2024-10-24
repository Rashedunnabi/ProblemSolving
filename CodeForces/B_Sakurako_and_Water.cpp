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
        int n, sum = 0;
        cin >> n;
        int sz = 4 * n;
        vector<int> v(sz);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                int id = i - j + n;
                v[id] = min(x, v[id]);
            }
        }

        sum = -1 * accumulate(v.begin(), v.end(), 0LL);
        cout << sum << '\n';
    }
    return 0;
}