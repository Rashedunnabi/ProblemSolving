#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll i, n, k, q;
        cin >> n >> k >> q;
        vector<ll> point(k + 1), time(k + 1);
        for (i = 1; i <= k; i++)
            cin >> point[i];
        for (i = 1; i <= k; i++)
            cin >> time[i];

        while (q--)
        {
            ll x;
            cin >> x;
            auto it = lower_bound(point.begin(), point.end(), x);
            ll ind = it - point.begin();
            if (*it == x)
                cout << time[ind] << ' ';
            else
            {
                it--;
                ll ind = it - point.begin();
                ll totalTime = time[ind];
                ll difTime = time[ind + 1] - time[ind];
                ll difDis = point[ind + 1] - point[ind];
                ll extra = (x - point[ind]);
                ll extraTime = ((difTime * 1LL * extra) / difDis);
                totalTime += extraTime;
                cout << totalTime << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}