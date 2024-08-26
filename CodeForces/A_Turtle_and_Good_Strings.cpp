#include <bits/stdc++.h>
using namespace std;
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
        cout << (s[0] != s[n - 1] ? "YES\n" : "NO\n");
    }
    return 0;
}