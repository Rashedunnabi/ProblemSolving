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
        int n, k, i;
        cin >> n >> k;

        if (k == 1)
        {
            for (i = 0; i < n; i++)
                cout << i + 1 << ' ';
            cout << '\n';
        }
        else if (k == n)
        {
            for (i = 0; i < n; i++)
                cout << 1 << ' ';
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }
    return 0;
}