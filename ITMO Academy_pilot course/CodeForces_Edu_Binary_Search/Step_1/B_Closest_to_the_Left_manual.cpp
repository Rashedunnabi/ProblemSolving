#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, q, i;
    cin >> n >> q;
    vector<int> v(n + 2);
    for (i = 1; i <= n; i++)
        cin >> v[i];

    while (q--)
    {
        int x;
        cin >> x;

        int hi = n, lo = 0, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (x < v[mid])
                hi = mid;
            else
                lo = mid;
        }
        if (v[hi] <= x)
            cout << hi << '\n';
        else
            cout << lo << '\n';
    }

    return 0;
}