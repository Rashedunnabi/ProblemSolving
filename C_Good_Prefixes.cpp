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
        int n, i, sum = 0LL, maxi = 0LL, cnt = 0;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        for (i = 0; i < n; i++)
        {
            if (v[i] > maxi)
                maxi = v[i];
            sum += v[i];
            if (maxi == sum - maxi || (!sum && !v[i]))
                cnt++;
        }

        cout << cnt << endl;
    }
    return 0;
}