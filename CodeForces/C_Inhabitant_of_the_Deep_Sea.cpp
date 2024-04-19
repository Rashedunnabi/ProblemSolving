#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll n, k, sum = 0, i;
    cin >> n >> k;
    ll arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum <= k)
    {
        cout << n << '\n';
        return;
    }
    ll l = 0, r = n - 1;
    ll ans = 0;
    int cnt = 1;
    while (l < r && k > 0)
    {
        if (cnt & 1)
        {
            ll mini = min(arr[l], arr[r]);
            if (mini == arr[l])
            {
                ll x = mini * 2 - 1;

                if (k < x)
                    break;
                ans++;
                l++;
                arr[r] = arr[r] - mini + 1;
                cnt = 2;
                k -= x;
            }
            else
            {
                ll x = mini * 2;
                if (k < x)
                    break;
                ans++;
                r--;
                arr[l] = arr[l] - mini;
                cnt = 1;
                k -= x;
            }
        }
        else
        {
            ll mini = min(arr[l], arr[r]);
            if (mini == arr[r])
            {
                ll x = mini * 2 - 1;
                if (k < x)
                    break;
                ans++;
                r--;
                arr[l] = arr[l] - mini + 1;
                cnt = 1;
                k -= x;
            }
            else
            {
                ll x = mini * 2;
                if (k < x)
                    break;
                ans++;
                l++;
                arr[r] = arr[r] - mini;
                cnt = 2;
                k -= x;
            }
        }
    }
    if (l == r && arr[l] <= k)
        ans++;
    cout << ans << endl;
}

signed main()
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