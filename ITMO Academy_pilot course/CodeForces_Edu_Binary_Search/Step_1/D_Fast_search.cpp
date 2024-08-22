#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    sort(v.begin(), v.end());
    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int dis = upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);
        cout << dis << ' ';
    }
    return 0;
}