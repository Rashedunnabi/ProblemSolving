#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const ll N = 2e5 + 7;
ll arr[N];

void solution()
{
    ll n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    vector<ll> v;
    v.push_back(arr[0]);

    for (i = 1; i < n; i++)
    {
        if (arr[i] != v.back())
            v.push_back(arr[i]);
    }
    ll ans = 1, dis1, dis2, dis;
    for (i = 0; i < v.size(); i++)
    {
        dis1 = lower_bound(v.begin(), v.end(), v[i]) - v.begin();
        dis2 = lower_bound(v.begin(), v.end(), v[i] + n) - v.begin();
        dis = dis2 - dis1;
        ans = max(ans, dis);
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