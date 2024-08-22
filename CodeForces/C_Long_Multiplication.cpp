#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        bool flag = 0;

        int i, n = a.length();
        for (i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                continue;
            if (a[i] != b[i])
            {
                if (!flag)
                    flag = 1;
                else
                {
                    if (a[i] > b[i])
                        swap(a[i], b[i]);
                }
            }
        }
        cout << a << '\n'
             << b << '\n';
    }
    return 0;
}