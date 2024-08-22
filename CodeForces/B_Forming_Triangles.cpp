#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll n, i, ans = 0, choto = 0;
    cin >> n;
    vector<ll> cnt(n + 1), a;
    for (i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (i = 0; i <= n; i++)
    {
        if (cnt[i])
            a.push_back(i);
    }

    for (i = 0; i < a.size(); i++)
    {
        int x = cnt[a[i]];
        if (x >= 3)
        {
            ans += (x * 1LL * (x - 1) * (x - 2) / 6);
        }
        if (x >= 2)
        {
            ans += (choto * 1LL * x * (x - 1) / 2);
        }
        choto += x;
    }
    cout << ans << '\n';
}

int main()
{
    Faster;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}