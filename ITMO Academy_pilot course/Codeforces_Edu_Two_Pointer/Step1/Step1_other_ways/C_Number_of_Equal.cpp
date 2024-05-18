#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, i;
    cin >> n >> m;
    map<int, int> a, b;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    long long ans = 0;
    for (auto &x : a)
    {
        long long cnt = (x.second * 1LL * b[x.first]);
        ans += cnt;
    }
    cout << ans << '\n';
    return 0;
}