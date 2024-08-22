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
        vector<bool> vis(n + 3);
        for (int &i : v)
            cin >> i;

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int e = v[i];
            if (i == 0)
                vis[e] = true;
            else
            {
                vis[e] = true;
                if (!(vis[e + 1] || vis[e - 1]))
                {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}