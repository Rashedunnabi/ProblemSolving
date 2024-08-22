#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll n, k, x, i, ans = INT_MIN;
    cin >> n >> k >> x;

    int arr[n], pre[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    pre[0] = arr[0];
    for (i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i];

    if (k >= n)
        ans = 0;

    for (i = 0; i <= k; i++)
    {

        ll lst = n - 1 - i;
        if (lst >= 0)
        {
            ll a = pre[lst], b = 0;
            if (lst - x >= 0)
            {
                a = pre[lst] - pre[lst - x];
                b = pre[lst - x];
            }
            a = b - a;
            ans = max(ans, a);
        }
    }
    cout << ans << '\n';
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