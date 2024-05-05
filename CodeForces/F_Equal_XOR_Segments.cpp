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
        int n, q, i;
        cin >> n >> q;
        vector<int> v(n), preXor(n + 1);
        for (int &i : v)
            cin >> i;

        map<int, vector<int>> mp;
        mp[0].push_back(0);

        for (i = 0; i < n; i++)
        {
            preXor[i + 1] = preXor[i] ^ v[i];
            mp[preXor[i + 1]].push_back(i + 1);
        }

        while (q--)
        {
            int l, r, value;
            cin >> l >> r;
            value = preXor[r] ^ preXor[l - 1];

            if (value == 0)
            {
                cout << "YES\n";
                continue;
            }
            auto &v1 = mp[preXor[r]], &v2 = mp[preXor[l - 1]];
            auto it1 = lower_bound(v1.begin(), v1.end(), l);   // r er jonno l khujbo
            auto it2 = --lower_bound(v2.begin(), v2.end(), r); // l er jonno r khujbo
            cout << (*it1 < *it2 ? "YES\n" : "NO\n");
        }
        cout << '\n';
    }
    return 0;
}
