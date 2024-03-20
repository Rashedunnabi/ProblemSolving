#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, target, ind, i;
        cin >> n >> target;
        vector<int> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == target)
                ind = i + 1;
        }

        int lo = 0, hi = n, mid;
        while (hi - lo > 1)
        {
            mid = lo + (hi - lo) / 2;
            if (v[mid] <= target)
                lo = mid;
            else
                hi = mid;
        }

        if (v[mid] == target)
            cout << 0 << '\n';
        else
            cout << 1 << '\n'
                 << lo + 1 << ' ' << ind << '\n';
    }
    return 0;
}