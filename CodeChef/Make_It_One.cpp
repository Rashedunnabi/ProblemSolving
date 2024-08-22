#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

void solution()
{
    int l, r, n, i;
    cin >> l >> r;
    n = r - l + 1;
    int a[n + 5], b[n + 5];
    r = l;

    for (i = 0; i < n; i++)
    {
        a[i] = b[i] = r++;
    }

    if (n == 1)
    {
        cout << ((l == 1) ? 1 : -1) << '\n';
        return;
    }

    if (n % 2 == 0)
    {
        for (i = 0; i < n; i += 2)
        {
            swap(b[i], b[i + 1]);
        }
    }
    else
    {
        if (l % 2 == 0)
        {
            cout << -1 << '\n';
            return;
        }
        for (i = 0; i < n - 3; i += 2)
            swap(b[i], b[i + 1]);
        swap(b[n - 1], b[n - 2]);
        swap(b[n - 2], b[n - 3]);
    }
    for (i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

    cout << '\n';
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
