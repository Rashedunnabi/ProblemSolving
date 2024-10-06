#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 7;

int wt[105], val[105];
int dp[N];

int func(int i, int value, int capacity)
{
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int item, capacity;
    cin >> item >> capacity;

    for (int i = 0; i < item; i++)
        cin >> wt[i] >> val[i];

    memset(dp, -1, sizeof(dp));

    for (int i = N; i >= 0; i--)
    {
        if (func(item - 1, i, capacity))
        {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}