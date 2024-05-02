#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, ans = 0, preVal = -1;
        cin >> n;

        for (i = 1; i < n; i++)
        {
            int val = __gcd(n, i) + i;
            if (val > preVal)
            {
                preVal = val;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}