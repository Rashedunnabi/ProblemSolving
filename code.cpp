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
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        set<vector<int>> st;

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        if (i == j || i == k || i == l || j == k || j == l || k == l)
                            continue;

                        int a = v[i] ^ v[j];
                        int b = v[j] ^ v[k];
                        int c = v[k] ^ v[l];
                        int d = v[l] ^ v[i];
                        if (a == c && b == d && a > 0 && b > 0)
                            cnt++;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}