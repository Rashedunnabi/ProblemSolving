#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solution()
{
    int n, i;
    cin >> n;
    string s;
    cin >> s;

    int p = 0, m = 0, mp = 0, ans = 0;

    for (i = 0; i < n - 2; i++)
    {
        string ss = s.substr(i, 3);
        if (ss == "pie")
            p++;
        if (ss == "map")
            m++;
    }
    for (i = 0; i < n - 4; i++)
    {
        string ss = s.substr(i, 5);
        if (ss == "mapie")
            mp++;
    }
    ans = p + m - mp;
    cout << ans << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}