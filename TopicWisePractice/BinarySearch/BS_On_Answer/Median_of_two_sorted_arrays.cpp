#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2)
        return findMedianSortedArrays(b, a);
    int n = n1 + n2;
    int left = (n + 1) / 2;
    int lo = 0, hi = n1;
    while (lo <= hi)
    {
        int mid1 = (hi + lo) / 2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        int mid2 = left - mid1;
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n & 1)
                return max(l1, l2);
            else
                return double(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            hi = mid1 - 1;
        else
            lo = mid1 + 1;
    }
    return 0.0;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << findMedianSortedArrays(a, b) << '\n';
    return 0;
}