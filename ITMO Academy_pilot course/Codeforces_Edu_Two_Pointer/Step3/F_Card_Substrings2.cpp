#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    string txt, pat;
    cin >> n >> m >> txt >> pat;

    vector<int> cnt(27), cur(27);
    for (auto it : pat)
        cnt[it - 'a']++;

    int l = 0, r = 0, ans = 0;
    for (r = 0; r < n; r++)
    {
        int it = txt[r] - 'a';
        cur[it]++;
        while (cur[it] > cnt[it])
        {
            int itt = txt[l++] - 'a';
            cur[itt]--;
        }
        ans += r - l + 1;
    }
    cout << ans << '\n';
    return 0;
}