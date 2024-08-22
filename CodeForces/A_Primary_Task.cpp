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
        string s;
        cin >> s;
        if (s.length() <= 2 || (s.length() == 3 && s[2] < '2') || s[0] != '1' || s[1] != '0' || s[2] == '0')
            no;
        else
            yes;
    }
    return 0;
}