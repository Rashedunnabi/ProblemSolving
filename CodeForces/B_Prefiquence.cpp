#include <bits/stdc++.h>
using namespace std;
#define int long long

int maxPrefixSubsequence(string a, string b)
{
    int i, k, j, ans = 0, p = 0;
    int n = a.length(), m = b.length();
    for (i = 0; i < n; i++)
    {
        k = 0;
        for (j = p; j < m; j++)
        {
            if (a[i] == b[j])
            {
                ans++, k++;
                p = j + 1;
                break;
            }
        }
        if (j >= m || k == 0)
            break;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, i, j;
        string s, t;
        cin >> n >> m >> s >> t;
        cout << maxPrefixSubsequence(s, t) << '\n';
    }
    return 0;
}