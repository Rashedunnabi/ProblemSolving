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
        int ar[3];
        cin >> ar[0] >> ar[1] >> ar[2];

        for (int i = 0; i < 5; i++)
        {
            sort(ar, ar + 3);
            ar[0]++;
        }

        int ans = ar[0] * 1LL * ar[1] * ar[2];
        cout << ans << '\n';
    }
    return 0;
}