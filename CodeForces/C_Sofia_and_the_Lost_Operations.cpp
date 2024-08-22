#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, m;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;

        cin >> m;
        vector<int> d(m);
        for (int &i : d)
            cin >> i;

        map<int, int> cnt1, cnt2;
        for (i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                cnt1[b[i]]++;
        }
        for (auto i : d)
            cnt2[i]++;

        bool flag = 1;
        for (i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (cnt1[b[i]] > cnt2[b[i]])
                    flag = 0;
            }
        }
        if (!flag)
        {
            cout << "NO\n";
            continue;
        }
        flag = (find(b.begin(), b.end(), d.back()) != b.end());
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}