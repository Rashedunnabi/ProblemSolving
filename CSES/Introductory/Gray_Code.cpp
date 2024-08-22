#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, i, j, r;
    cin >> n;
    r = pow(2, n);

    int arr[r][n];

    for (i = 0; i < r; i++)
    {
        for (j = n - 1; j >= 0; j--)
        {
            arr[i][j] = ((i >> j) & 1);
        }
    }

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < n - 1; j++)
            arr[i][j] ^= arr[i][j + 1];
    }

    for (i = 0; i < r; i++)
    {
        for (j = n - 1; j >= 0; j--)
            cout << arr[i][j];
        cout << endl;
    }
    return 0;
}