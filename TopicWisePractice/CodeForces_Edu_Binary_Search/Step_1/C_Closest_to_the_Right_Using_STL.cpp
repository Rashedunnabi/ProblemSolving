#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, q, i;
    cin >> n >> q;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    while (q--)
    {
        int x;
        cin >> x;
        cout << (lower_bound(v.begin(), v.end(), x) - v.begin()) + 1 << '\n';
    }
    return 0;
}