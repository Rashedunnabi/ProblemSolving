#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int dp[110][N], wt[N], val[N];
int knapsak(int i, int bagCapacity)
{
    if (i < 0)
        return 0;
    if (dp[i][bagCapacity] != -1)
        return dp[i][bagCapacity];

    int maxValueGet = knapsak(i - 1, bagCapacity); // not take
    if (bagCapacity - wt[i] >= 0)                  // take
        maxValueGet = max(maxValueGet, knapsak(i - 1, bagCapacity - wt[i]) + val[i]);
    return dp[i][bagCapacity] = maxValueGet;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(dp, -1, sizeof(dp));

    int item, bagCapacity;
    cin >> item >> bagCapacity;
    for (int i = 0; i < item; i++)
        cin >> wt[i] >> val[i];
    cout << knapsak(item - 1, bagCapacity) << '\n';
    return 0;
}