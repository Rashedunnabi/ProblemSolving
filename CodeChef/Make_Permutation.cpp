#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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

        int maxi = *max_element(all(v));
        maxi = max(maxi, n);
        sort(all(v));

        int cur = 1;
        bool flag = true;
        for (i = 0; i < n; i++)
        {
            if (v[i] > cur)
                flag = false;
            cur++;
        }

        if (maxi > n)
            flag = false;

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}