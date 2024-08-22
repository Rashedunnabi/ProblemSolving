#include <bits/stdc++.h>
using namespace std;

#define int long long
bool check(int mid, vector<int> &a, vector<int> &b, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        int total = a[i] * mid;
        if (b[i] + k < total)
            return false;
        int need = max(0LL, total - b[i]);
        k -= need;
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, k, i;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    int lo = 0, hi = 1e9 + 7;
    for (i = 0; i < 62; i++)
    {
        int mid = 1LL << i;
        if (!check(mid, a, b, n, k))
        {
            hi = mid;
            break;
        }
    }

    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        check(mid, a, b, n, k) ? lo = mid : hi = mid;
    }
    cout << lo << '\n';

    return 0;
}