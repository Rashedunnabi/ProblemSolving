#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, i, j;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
                i++, j++;
            else
                j++;
        }
        cout << i << '\n';
    }
    return 0;
}