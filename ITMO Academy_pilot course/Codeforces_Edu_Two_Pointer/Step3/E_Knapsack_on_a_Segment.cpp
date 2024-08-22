#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, r = 0, BagCapacity, MaxCost = INT_MIN, weightSum = 0, costSum = 0;
    cin >> n >> BagCapacity;
    vector<int> weight(n), cost(n);
    for (int &i : weight)
        cin >> i;
    for (int &i : cost)
        cin >> i;

    for (int l = 0; l < n; l++)
    {
        while (r < n && weightSum + weight[r] <= BagCapacity)
        {
            weightSum += weight[r];
            costSum += cost[r++];
        }
        if (weightSum <= BagCapacity)
            MaxCost = max(MaxCost, costSum);

        weightSum -= weight[l];
        costSum -= cost[l];
    }
    cout << MaxCost << '\n';
}