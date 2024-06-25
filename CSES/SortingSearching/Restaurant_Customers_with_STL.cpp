#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, ans = 1, sum = 0;
    cin >> n;

    map<int, int> audiance; // time --> number
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        audiance[a]++;
        audiance[b]--;
    }
    for (auto x : audiance)
    {
        sum += x.second;
        ans = max(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}