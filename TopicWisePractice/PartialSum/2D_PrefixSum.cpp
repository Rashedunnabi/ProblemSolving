#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 7;
int ar[N][N], p[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m, i, j;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cin >> ar[i][j];
    }

    // build the arrar p that contain prefixSum till p[1][1]....p[i][j]
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            p[i][j] = ar[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, u, d;
        cin >> u >> l >> d >> r;
        int sum = p[d][r] - p[u - 1][r] - p[d][l - 1] + p[u - 1][l - 1];
        cout << sum << '\n';
    }

    return 0;
}

/*
Time complexity: O(n*m+q) ==> O(n^2)
*/