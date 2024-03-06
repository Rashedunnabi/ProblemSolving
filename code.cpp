#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()

void solution()
{
    ll n, time, i;
    cin >> n >> time;

    vector<pair<ll, ll>> vp;
    for (i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    sort(all(vp));

    ll pre = 0, sum = 0, cnt = 0;

    for (i = 0; i < n; i++)
    {
        ll a = vp[i].first, b = vp[i].second;

        if (i == 0)
        {
            if (a > time)
                break;
            cnt++;
            sum += 0LL + a;
            pre = b;
        }
        else
        {
            if (sum + 0LL + a + abs(b - pre) > time + 0LL)
            {
                break;
            }
            cnt++;
            sum += 0LL + a + abs(b - pre);
            pre = b;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}