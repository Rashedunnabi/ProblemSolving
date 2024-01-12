#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N];
int dp[N];

int lis(int i)
{
    if (dp[i] != -1)
        return dp[i];

    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j] < a[i])
            ans = max(ans, lis(j) + 1);
    }

    return dp[i] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << lis(n - 1) << '\n';

    return 0;
}