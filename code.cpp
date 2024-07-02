#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, ans = 0;
        cin >> n >> k;

        int numOfOdd = (n + 1) / 2;
        for (int i = 0; i < 32; i++)
        {
            int numOfValue = n / (1LL << i);
            numOfOdd = (numOfValue + 1) / 2;
            if (k <= numOfOdd)
            {
                ans = (2 * k - 1) * (1LL << i);
                break;
            }
            k -= numOfOdd;
        }
        cout << ans << '\n';
    }
    return 0;
}