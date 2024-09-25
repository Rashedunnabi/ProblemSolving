#include <bits/stdc++.h>
using namespace std;
#define int long long
bool findMaxi(const vector<int> &v, int mid)
{
    int extra = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > mid)
            extra += v[i] - mid;
        else
            extra = max(extra - (mid - v[i]), 0LL);
    }
    return extra == 0;
}
bool findMini(const vector<int> &v, int mid)
{
    int extra = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= mid)
            extra += v[i] - mid;
        else
        {
            extra -= mid - v[i];
            if (extra < 0)
                return false;
        }
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, mx = -1, mn = INT_MAX;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
        {
            cin >> i;
            mn = min(mn, i), mx = max(mx, i);
        }
        int lo = mn, hi = mx;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (findMaxi(v, mid))
                hi = mid;
            else
                lo = mid;
        }
        int maxi = hi, mini = lo;
        lo = mn, hi = mx;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (findMini(v, mid))
                lo = mid;
            else
                hi = mid;
        }
        mini = lo;
        cout << maxi - mini << '\n';
    }

    return 0;
}