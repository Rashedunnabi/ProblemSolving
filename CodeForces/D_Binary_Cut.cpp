#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int ans = 0, zeroOne = 0;
        char pre;
        for (int i = 0; i < s.length(); i++)
        {
            if (i == 0)
                pre = s[i];
            if (s[i] == pre)
                continue;
            else
            {
                if (pre == '0')
                {
                    pre = s[i];
                    if (zeroOne == 0)
                        zeroOne = 1;
                    else
                        ans++;
                }
                else
                {
                    ans++;
                    pre = s[i];
                }
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}