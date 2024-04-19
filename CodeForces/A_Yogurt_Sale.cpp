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
        int n, r, p, ans = 0;
        cin >> n >> r >> p;

        if (2 * r <= p)
        {
            ans = r * n;
        }
        else
        {
            ans = (n / 2) * p;
            if (n & 1)
                ans += r;
        }
        cout << ans << '\n';
    }
    return 0;
}