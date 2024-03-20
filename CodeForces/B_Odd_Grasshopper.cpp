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
        ll x, n, ans = 0;
        cin >> x >> n;

        n = 0;
        for (int i = 1; i <= 50; i++)
        {
            if (n & 1)
            {
                n += i;
            }
            else
            {
                n -= i;
            }
            cout << n << ' ';
        }
        cout << '\n';
    }
    return 0;
}