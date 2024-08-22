// Floyd Warshall Algorithm Problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 510, INF = LLONG_MAX;
ll dis[N][N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n, i, j, k;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> dis[i][j];
        }
    }

    vector<ll> del_order(n), ansSum;
    for (ll &i : del_order)
        cin >> i;
    reverse(del_order.begin(), del_order.end());

    for (ll k = 0; k < n; k++)
    {
        ll k_v = del_order[k];
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k_v] + dis[k_v][j]);
            }
        }

        ll sum = 0;
        for (i = 0; i <= k; i++)
        {
            for (j = 0; j <= k; j++)
            {
                sum += dis[del_order[i]][del_order[j]];
            }
        }
        ansSum.push_back(sum);
    }
    reverse(ansSum.begin(), ansSum.end());
    for (auto val : ansSum)
        cout << val << ' ';
    cout << '\n';

    return 0;
}