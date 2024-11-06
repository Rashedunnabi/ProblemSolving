#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        bool flag = 1;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        for (int i = 1; i < n; i++)
        {
            int dif = abs(v[i] - v[i - 1]);
            if (dif != 5 && dif != 7)
                flag = 0;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}