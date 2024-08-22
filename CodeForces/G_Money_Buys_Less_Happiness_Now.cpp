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
        int n, x, ans = 0, totalCost = 0;
        cin >> n >> x;
        vector<int> cost(n);
        for (int i = 0; i < n; i++)
            cin >> cost[i];

        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            if (totalCost >= cost[i])
            {
                totalCost -= cost[i];
                pq.push(cost[i]);
                ans++;
            }
            else if (!pq.empty() && pq.top() >= cost[i])
            {
                totalCost += pq.top();
                pq.pop();
                totalCost -= cost[i];
                pq.push(cost[i]);
            }
            totalCost += x;
        }
        cout << ans << '\n';
    }
    return 0;
}