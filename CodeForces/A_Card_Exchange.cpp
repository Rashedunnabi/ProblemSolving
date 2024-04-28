#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int i, n, k, ans = 0;
        cin >> n >> k;

        map<int, int> mp;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
            if (mp[x] == k)
                ans = k - 1;
        }
        if (!ans)
            ans = n;
        cout << ans << '\n';
    }
    return 0;
}