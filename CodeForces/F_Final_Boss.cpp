#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int at[N], cd[N];

bool isPossible(int mid, int health, int n)
{
    int cnt = 0, hSum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = (mid + cd[i] - 1) / cd[i];
        hSum += (x * at[i]);
    }
    return hSum >= health;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int h, n, i;
        cin >> h >> n;
        for (i = 1; i <= n; i++)
            cin >> at[i];
        for (i = 1; i <= n; i++)
            cin >> cd[i];

        int hi = -1, lo = 0;
        for (i = 0; i <= 63; i++)
        {
            int mid = (1LL << i);
            if (isPossible(mid, h, n))
            {
                hi = mid;
                break;
            }
        }

        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(mid, h, n))
                hi = mid;
            else
                lo = mid;
        }
        cout << hi << '\n';
    }
    return 0;
}