#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &e : v)
            cin >> e;
        ll lft = (k + 1) / 2;
        int i = 0;
        while (i < n && v[i] <= lft)
            lft -= v[i++];
        if (i < n)
            v[i] -= lft;
        int j = n - 1;
        ll rft = k / 2;
        while (j >= i && v[j] <= rft)
            rft -= v[j--];
        if (j >= i)
            cout << n - (j - i + 1) << "\n";
        else
            cout << n << "\n";
    }
    return 0;
}