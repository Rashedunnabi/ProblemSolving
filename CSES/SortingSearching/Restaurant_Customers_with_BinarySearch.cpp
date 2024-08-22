#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, i;
    cin >> n;

    vector<int> arrival(n), leaving(n);
    for (i = 0; i < n; i++)
        cin >> arrival[i] >> leaving[i];

    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());

    int ans = 1;

    for (i = 0; i < n; i++)
    {
        auto it = upper_bound(arrival.begin(), arrival.end(), leaving[i]);
        if (it == arrival.begin())
            continue;
        it--;
        int dis = it - arrival.begin();
        dis = dis - i + 1;
        ans = max(ans, dis);
    }
    cout << ans << '\n';
    return 0;
}