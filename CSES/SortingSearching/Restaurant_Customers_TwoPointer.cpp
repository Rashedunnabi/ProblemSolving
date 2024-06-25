#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;

    vector<int> arrival(n), leaving(n);
    for (int i = 0; i < n; i++)
        cin >> arrival[i] >> leaving[i];

    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());

    int ans = 1, l = 0, r = 0, cnt = 0;
    while (l < n && r < n)
    {
        if (arrival[l] < leaving[r])
        {
            cnt++;
            l++;
        }
        else
        {
            cnt--;
            r++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}