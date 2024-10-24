#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        map<int, int> mp;
        int sum = 0, cnt = 0;
        mp[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (mp[sum])
            {
                ++cnt;
                mp.clear();
                mp[0] = 1;
                sum = 0;
            }
            mp[sum] = 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}