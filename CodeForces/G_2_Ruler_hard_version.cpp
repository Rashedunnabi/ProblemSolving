#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int lo = 0, hi = 1000, area;
        while (hi - lo > 1)
        {
            int mid1 = (2 * lo + hi) / 3, mid2 = (lo + 2 * hi) / 3;

            cout << "? " << mid1 << " " << mid2 << endl;
            cin >> area;

            if (area == mid1 * mid2)
                lo = mid2;
            else if (area == mid1 * (mid2 + 1))
                lo = mid1, hi = mid2;
            else
                hi = mid1;
        }
        cout << "! " << hi << endl;
    }
    return 0;
}
