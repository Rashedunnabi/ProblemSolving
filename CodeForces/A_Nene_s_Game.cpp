#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int i, n, q, mini = INT_MAX;
        cin >> n >> q;
        for (i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mini = min(mini, x);
        }
        while (q--)
        {
            int x;
            cin >> x;
            cout << min(mini - 1, x) << ' ';
        }
        cout << '\n';
    }
    return 0;
}