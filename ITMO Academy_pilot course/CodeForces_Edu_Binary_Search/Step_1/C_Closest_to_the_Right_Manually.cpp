#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, q, i;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v[i];
    v.push_back(1e9 + 7);

    while (q--)
    {
        int x;
        cin >> x;

        int hi = n+1, lo = 1, mid;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (x <= v[mid])
                hi = mid;
            else
                lo = mid;
        }
         if (v[lo] >= x)
            cout << lo << '\n';
        else
            cout << hi << '\n';
    }

    return 0;
}