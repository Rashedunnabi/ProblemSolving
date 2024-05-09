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
        string s;
        cin >> n >> s;

        int a = 0, b = 0, cnt = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                a++;
            else if (s[i] == 'b' && a > 0)
                b = a;
            else if (s[i] == 'c' && a > 0 && b > 0)
            {
                cnt++;
                a--, b--;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}