#include <bits/stdc++.h>
using namespace std;
int t, n, k, i, j, hi, lo;
int arr[200005];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        lo = 1, hi = n;
        for (i = 1; i <= k; i++)
        {
            for (j = i; j <= n; j += k)
            {
                if (i & 1)
                    arr[j] = lo++;
                else
                    arr[j] = hi--;
            }
        }
        for (i = 1; i <= n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    return 0;
}