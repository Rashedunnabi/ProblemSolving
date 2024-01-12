#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    vector<int> f(32, 0);
    while (q--)
    {
        int t, x;
        scanf("%d %d", &t, &x);
        if (t == 1)
        {
            f[x]++;
            for (int i = x; i <= 30; ++i)
            {
                if (f[i] > 2)
                    f[i] -= 2, f[i + 1]++;
            }
        }
        else
        {
            for (int i = 30; i >= 0; --i)
            {
                for (int j = 0; j < f[i] and x >= (1 << i); ++j)
                    x -= 1 << i;
            }
            cout << (x ? "NO\n" : "YES\n");
        }
    }
    return 0;
}
