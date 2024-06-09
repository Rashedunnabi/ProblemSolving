#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        vector<int> cnt(7);
        int n, m, i;
        cin >> n >> m;
        for (i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            cnt[ch - 'A']++;
        }
        int ans = 0;
        for (i = 0; i < 7; i++)
            ans += (cnt[i] >= m ? 0 : m - cnt[i]);
        cout << ans << '\n';
    }
    return 0;
}