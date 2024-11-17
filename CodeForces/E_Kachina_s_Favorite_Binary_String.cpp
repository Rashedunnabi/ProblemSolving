#include <bits/stdc++.h>
using namespace std;
int get(int a, int b)
{
    int x;
    cout << "? " << a << ' ' << b << endl;
    cin >> x;
    return x;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (get(1, n) == 0)
        {
            cout << "! IMPOSSIBLE" << endl;
            continue;
        }

        string s(n, '0');
        int pre = -1;
        for (int i = 2; i <= n; i++)
        {
            int x = get(1, i);
            if (x)
            {
                if (pre == -1)
                {
                    int one = i - x - 1;
                    for (int j = 0; j < one; j++)
                        s[j] = '1';

                    s[i - 1] = '1';
                    pre = x;
                }
                else if (x > pre)
                {
                    s[i - 1] = '1';
                    pre = x;
                }
            }
        }
        cout << "! " << s << endl;
    }
    return 0;
}