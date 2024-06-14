#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 7, mod = 1e9 + 7;
int ar[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, q, i, j;
    cin >> n >> m >> q;

    while (q--)
    {
        int l, r, u, d, x;
        cin >> l >> r >> u >> d >> x;
        ar[u][l] += x;
        ar[u][r + 1] -= x;
        ar[d + 1][l] -= x;
        ar[d + 1][r + 1] += x;
    }

    // calculate the 2D partialSum for commulative value
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            ar[i][j] += ar[i - 1][j] + ar[i][j - 1] - ar[i - 1][j - 1];
        }
    }

    // print the final array
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cout << ar[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n*m+Q) => O(n^2)
*/