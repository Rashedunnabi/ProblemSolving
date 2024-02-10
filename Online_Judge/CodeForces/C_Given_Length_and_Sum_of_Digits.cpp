#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

char x[150];
int main()
{
    Faster;
    int m, s, ma = 0;
    cin >> m >> s;
    if (s == 0)
    {
        if (m == 1)
        {
            cout << "0 0";
            return 0;
        }
        else
        {
            cout << "-1 -1";
            return 0;
        }
    }
    if (s > 9 * m)
    {
        cout << "-1 -1";
        return 0;
    }
    // minimum
    for (int i = m - 1; i >= 0; --i)
    {
        if (s - ma > 9)
        {
            x[i] = '9';
            ma += 9;
        }
        else
        {
            x[i] = s - ma - 1 + '0';
            ma = s - 1;
            if (i == 0)
                x[i]++;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cout << x[i];
    }
    cout << " ";

    // maximum
    ma = 0;
    for (int i = 0; i < m; ++i)
    {
        if (s - ma >= 9)
        {
            cout << 9;
            ma += 9;
        }
        else
        {
            cout << s - ma;
            ma = s;
        }
    }

    return 0;
}