#include <bits/stdc++.h>
using namespace std;

void printVal(int n, int start)
{
    for (int i = 0, j = start; i < n / 2; i++, j++)
        cout << j << ' ' << j << ' ';
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n & 1)
        {
            if (n < 27)
                cout << -1 << '\n';
            else
            {

                for (int i = 1, start = 3; i <= 27; i++)
                {
                    if (i == 1 || i == 10 || i == 26)
                        cout << 1 << ' ';
                    else if (i == 23 || i == 27)
                        cout << 2 << ' ';
                    else
                    {
                        cout << start << ' ' << start << ' ';
                        start++;
                        i++;
                    }
                }
                int rest = n - 27;
                printVal(rest, 20);
            }
        }
        else
            printVal(n, 1);
    }
    return 0;
}