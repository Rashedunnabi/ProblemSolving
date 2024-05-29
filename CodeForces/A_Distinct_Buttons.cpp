#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;

        int up, down, left, right;
        up = down = left = right = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            if (y > 0)
                up = 1;
            if (y < 0)
                down = 1;
            if (x > 0)
                right = 1;
            if (x < 0)
                left = 1;
        }
        int x = up + down + left + right;
        cout << (x < 4 ? "YES\n" : "NO\n");
    }
    return 0;
}