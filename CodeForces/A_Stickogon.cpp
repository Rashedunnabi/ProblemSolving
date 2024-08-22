#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, ans = 0;
        cin >> n;
        map<int, int> mp;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        for (auto val : mp)
            ans += (val.second / 3);
        cout << ans << '\n';
    }
    return 0;
}