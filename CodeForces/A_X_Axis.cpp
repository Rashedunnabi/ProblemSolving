#include <bits/stdc++.h>
using namespace std;

int func(int a, int b, int c, int x)
{
    return abs(a - x) + abs(b - x) + abs(c - x);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int testCase;
    cin >> testCase;
    for (int tc = 1; tc <= testCase; tc++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = min({func(a, b, c, a), func(a, b, c, b), func(a, b, c, c)});
        cout << ans << '\n';
    }
    return 0;
}