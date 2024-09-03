#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int zero = count(s.begin(), s.end(), '0');
        int row = sqrt(n), col = sqrt(n);
        if (row * col != n || (row - 2) * (col - 2) != zero)
            no;
        else
            yes;
    }
    return 0;
}