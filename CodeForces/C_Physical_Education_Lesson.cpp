#include <bits/stdc++.h>
using namespace std;
int t, n, m;
set<int> s;
inline void solve(int x)
{
    if (x < 2)
        return;

    for (int i = 1; i <= sqrt(x); i++)
    {
        // if not divisiable
        if (x % i != 0)
            continue;

        if ((i + 2) / 2 >= m && i % 2 == 0)
            s.insert(i);
        if ((x / i) != i && (x / i) % 2 == 0 && ((x / i) + 2) / 2 >= m)
            s.insert(x / i);
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        s.clear();
        solve(n - m);
        solve(n + m - 2);
        printf("%d\n", s.size());
    }
    return 0;
}