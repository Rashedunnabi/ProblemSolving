#include <bits/stdc++.h>
using namespace std;
#define int long long

bool possible(vector<int> &v, int mid, int k)
{
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.rbegin(), v.rend());
        int lo = 0, hi = 1e14 + 7;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (possible(v, mid, k))
                hi = mid;
            else
                lo = mid;
        }
        cout << hi << '\n';
    }
    return 0;
}