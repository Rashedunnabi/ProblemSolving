#include <bits/stdc++.h>
using namespace std;
#define int long long

int dis(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int x, y;
    cin >> x >> y;

    for (int i = x - 100; i <= x + 100; i++)
    {
        for (int j = x - 100; j <= x + 100; j++)
        {
            int a = dis(x, y, i, 0);
            int b = dis(x, y, j, 0);
            int c = dis(i, 0, j, 0);
            if (a + b == c)
            {
                cout << "{" << i << ',' << 0 << " : " << j << ',' << 0 << " : " << "}\n";
            }
        }
    }

    return 0;
}