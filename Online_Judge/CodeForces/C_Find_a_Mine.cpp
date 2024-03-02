#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL)

void solution()
{
    int n, m, x, y, z = -1, r1, r2, c1, c2;
    cin >> n >> m;

    cout << "? 1 1" << endl;
    cin >> x;
    cout << "? 1 " << m << endl;
    cin >> y;
    r1 = (x + y - m + 2) / 2;
    r1 += 1;
    c1 = x - r1 + 2;

    if (r1 >= 1 && c1 >= 1 && r1 <= n && c1 <= m)
    {
        cout << "? " << r1 << ' ' << c1 << endl;
        cin >> z;
    }
    if (z == 0)
    {
        cout << "! " << r1 << ' ' << c1 << endl;
        return;
    }

    cout << "? " << n << " 1" << endl;
    cin >> y;

    c2 = (x + y - n + 2) / 2;
    c2 += 1;
    r2 = x - c2 + 2;

    cout << "! " << r2 << ' ' << c2 << endl;
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