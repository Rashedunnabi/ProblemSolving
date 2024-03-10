#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll n, time, i;
    cin >> n >> time;
    vector<pair<ll, ll>> vp(n);
    for (i = 0; i < n; i++)
        cin >> vp[i].second >> vp[i].first;
    sort(vp.begin(), vp.end());

    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        priority_queue<ll> q;
        ll sum = 0, cnt = 0;
        for (ll j = i; j < n; j++)
        {
            q.push(vp[j].second);
            sum += vp[j].second, cnt++;
            if (sum + vp[j].first - vp[i].first > time)
            {
                ll tp = q.top();
                q.pop();
                sum -= tp, cnt--;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
}

int main()
{
    Faster;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}