#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> z_function(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        if (n & 1)
        {
            cout << 0 << '\n';
            continue;
        }

        string t = s;
        reverse(t.begin(), t.end());

        auto prefix = z_function(s);
        auto suffix = z_function(t);

        int ans = 0;
        for (int p = 0; p <= (n / 2); p++) // p size of P,,,r size of R
        {
            int r = (n / 2) - p;
            if (prefix[p] >= p && suffix[r] >= r)
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}