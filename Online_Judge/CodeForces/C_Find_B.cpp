#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solution()
{
    ll n, i, q;
    cin >> n >> q;
    vector<ll> v(n), arr(n + 1);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
            arr[i + 1] = arr[i] + 1;
        else
            arr[i + 1] = arr[i];
    }
    vector<ll> preSum(n + 1);
    for (i = 1; i <= n; i++)
    {
        preSum[i] = preSum[i - 1] + v[i - 1] - 1;
    }

    for (auto val : v)
        cout << val << ' ';
    cout << '\n';
    for (i = 1; i <= n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    for (i = 1; i <= n; i++)
        cout << preSum[i] << ' ';
    cout << '\n';

    for (i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        if (l == r)
        {
            no;
            continue;
        }

        ll cnt = arr[r] - arr[l - 1];
        ll sum = preSum[r] - preSum[l - 1];
        if (sum >= cnt)
            yes;
        else
            no;
    }
}

main()
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