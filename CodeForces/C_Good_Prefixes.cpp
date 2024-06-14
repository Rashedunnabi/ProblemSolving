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
        int n, i, sum = 0LL, maxi = 0LL, cnt = 0;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        for (i = 0; i < n; i++)
        {
            maxi = max(maxi, v[i]);
            sum += v[i];
            if (maxi == sum - maxi)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}