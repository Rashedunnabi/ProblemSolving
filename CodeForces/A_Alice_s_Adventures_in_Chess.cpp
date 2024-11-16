#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, a, b, x = 0, y = 0, flag = 0, cnt = 50;

        string s;
        cin >> n >> a >> b >> s;

        while (cnt--)
        {
            for (char &ch : s)
            {
                if (x == a && y == b)
                    flag = 1;

                if (ch == 'N')
                    y++;
                if (ch == 'S')
                    y--;
                if (ch == 'E')
                    x++;
                if (ch == 'W')
                    x--;

                if (x == a && y == b)
                    flag = 1;
            }
        }
        if (flag)
            yes;
        else
            no;
    }
    return 0;
}