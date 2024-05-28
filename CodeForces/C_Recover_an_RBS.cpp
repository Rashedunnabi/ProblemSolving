#include <bits/stdc++.h>
using namespace std;

bool check(string &s)
{
    int i, n = s.length(), cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else
            cnt--;

        if (cnt < 0)
            return false;
    }
    return cnt == 0;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int i, n = s.length(), open = 0, close = 0, extra = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '?')
                extra++;
            else if (s[i] == '(')
                open++;
            else
                close++;
        }
        int need = close - open;
        int requiredOpening = (extra + need) / 2;
        int requireClosing = (extra - need) / 2;

        if (!requiredOpening || !requireClosing)
        {
            cout << "YES\n";
            continue;
        }

        int indOpen = -1, indClose = -1;
        for (i = 0; i < n; i++)
        {
            if (s[i] != '?')
                continue;
            if (requiredOpening-- > 0)
            {
                s[i] = '(';
                indOpen = i;
            }
            else if (requireClosing-- > 0)
            {
                s[i] = ')';
                if (indClose == -1)
                    indClose = i;
            }
        }
        swap(s[indClose], s[indOpen]);
        cout << (check(s) ? "NO\n" : "YES\n");
    }
    return 0;
}