#include <bits/stdc++.h>
using namespace std;
#define yes cout << "YES\n"
#define no cout << "NO\n"
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool flag = true;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        v.push_back(n + 1);

        for (int i = 0; i < n; i++)
        {
            if (v[i] == i + 1)
                continue;

            int soto = min(v[i], v[i + 1]);
            int boro = max(v[i], v[i + 1]);
            if (i + 1 != soto || i + 2 != boro)
            {
                flag = false;
                break;
            }
            else
                i++;
        }
        if (flag)
            yes;
        else
            no;
    }
    return 0;
}