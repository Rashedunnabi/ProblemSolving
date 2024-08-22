#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        int last = v[n - 1];
        cout << last << ' ';
        for (i = 0; i < n - 1; i++)
            cout << v[i] << ' ';
        cout << '\n';
    }
    return 0;
}