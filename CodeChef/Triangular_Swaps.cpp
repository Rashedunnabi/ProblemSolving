#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        ll n, ans = 0;
        cin >> n >> s;

        bool flag = false;
        for (int i = 2; i < n; i++)
        {
            if (s[i - 2] == s[i - 1] && s[i - 2] == s[i])
            {
                flag = true;
                continue;
            }

            if (i - 3 >= 0)
            {
                if (!(s[i - 3] == s[i - 2] && s[i - 2] == s[i]))
                    ans++;
            }
            else
            {
                ans++;
            }
        }
        ans += flag;
        cout << ans << '\n';
    }
    return 0;
}