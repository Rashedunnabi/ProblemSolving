#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()

void solution()
{
    int n, time, i, ans = 0;
    cin >> n >> time;

    vector<pair<int, int>> vp(n);
    for (auto &it : vp)
        cin >> it.second >> it.first;
    sort(all(vp));

    for (int i = 0; i < n; i++)
    {
        priority_queue<ll> pq;
        ll sum = 0, count = 0;
        for (ll j = i; j < n; ++j)
        {
            sum += vp[j].second;
            pq.push(vp[j].second);
            count++;
            while (!pq.empty() && (sum + (vp[j].first - vp[i].first)) > time)
            {
                sum -= pq.top();
                pq.pop();
                count--;
            }
            ans = max(ans + 0LL, count);
        }
    }
    cout << ans << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}