#include <bits/stdc++.h>
using namespace std;

const int N = 5050;
int arr[N][N], dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, i;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> arr[1][i];
        dp[1][i] = arr[1][i];
    }

    for (i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = arr[i - 1][j] ^ arr[i - 1][j + 1];
            dp[i][j] = max(arr[i][j], max(dp[i - 1][j], dp[i - 1][j + 1]));
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int row = r - l + 1;
        int col = l;
        cout << dp[row][col] << '\n';
    }

    return 0;
}