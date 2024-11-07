#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, x, ans = 0;
        cin >> n >> x;
        vector<int> a(n), b(n), v;
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
                ans++;
            else
                v.push_back(b[i] - a[i]);
        }
        sort(all(v));

        for (int i = 0; i < v.size() && x > 0; i++)
        {
            if (x - 1 < v[i])
                break;
            x = x - 1 - v[i];
            ans++;
        }
        if (ans > (n / 2))
            yes;
        else
            no;
    }
    return 0;
}