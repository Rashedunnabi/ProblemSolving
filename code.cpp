#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, ind;
        cin >> n >> m;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == m)
                ind = i;
        }

        int lo = 0, hi = n;
        while ((hi - lo) > 1)
        {
            int mid = (hi + lo) / 2;
            if (arr[mid] <= m)
                lo = mid;
            else
                hi = mid;
        }

        if (arr[lo] == m)
        {
            cout << 0 << endl;
            continue;
        }
        {
            cout << 1 << endl;
            int mn = min(ind, lo);
            int mx = max(ind, lo);
            cout << mn + 1 << " " << mx + 1 << endl;
        }
    }
    return 0;
}