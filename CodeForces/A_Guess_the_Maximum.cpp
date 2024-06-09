#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        int ans = INT_MAX;
        for (i = 0; i < n - 1; i++)
            ans = min(ans, max(v[i], v[i + 1]));
        cout << ans - 1 << '\n';
    }
    return 0;
}