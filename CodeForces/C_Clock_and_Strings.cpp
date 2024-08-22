#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int cnt = 0;
        for (int i = min(a, b); i <= max(a, b); i++)
        {
            if (i == c || i == d)
                cnt++;
        }
        cout << (cnt == 1 ? "YES\n" : "NO\n");
    }
    return 0;
}