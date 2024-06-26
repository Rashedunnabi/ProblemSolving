#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> z_function(const string &s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
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
        int n = s.size();

        if (n % 2 != 0)
        {
            cout << 0 << endl;
            continue;
        }

        vector<int> z = z_function(s);
        vector<int> start_P;
        for (int i = 0; i < n; ++i)
        {
            if (i <= z[i])
            {
                start_P.push_back(i);
            }
        }

        reverse(s.begin(), s.end());
        vector<int> z_rev = z_function(s);
        reverse(s.begin(), s.end());

        vector<int> start_R;
        for (int i = 0; i < n; ++i)
        {
            if (i <= z_rev[i])
            {
                start_R.push_back(n - i - 1);
            }
        }

        set<int> s_set(start_R.begin(), start_R.end());
        int ans = 0;

        for (int i : start_P)
        {
            int end = 2 * i;
            int size = (n - 1) - end + 1;
            size = size / 2;
            int coord = (n - 1) - size;
            if (s_set.find(coord) != s_set.end())
            {
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}