#include <bits/stdc++.h>
using namespace std;

main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        long long n, k, i;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        map<int, long long> mp;

        for (auto &e : a)
            cin >> e;
        for (auto &e : b)
            cin >> e;

        for (i = 0; i < n; i++)
        {
            long long x = abs(b[i]);
            mp[x] += a[i];
        }

        long long joma = 0, cnt = 0;
        bool flag = 0;
        for (auto val : mp)
        {
            long long ind = val.first, value = val.second;

            long long x = (ind - cnt) * k;
            if (joma + x < value)
                flag = 1;

            cnt = ind;
            joma = joma + x - value;
        }

        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}