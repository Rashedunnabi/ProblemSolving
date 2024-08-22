#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int hi = 999, lo = 2, mid, area;
        while (hi > lo)
        {
            mid = (hi + lo) / 2;
            cout << "? " << mid << ' ' << mid << endl;
            cin >> area;
            if (area > mid * mid)
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << "! " << hi << endl;
    }
    return 0;
}
