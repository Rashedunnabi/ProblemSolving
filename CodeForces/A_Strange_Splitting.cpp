#include <bits/stdc++.h>
using namespace std;
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

        if (v.back() == v.front())
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << "BR";
            for (int i = 2; i < n; i++)
                cout << 'B';
            cout << "\n";
        }
    }
    return 0;
}