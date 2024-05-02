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
        cin >> s;
        ll ans = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                cnt++;
            else if (cnt)
                ans += (cnt + 1);
        }
        cout << ans << endl;
    }
    return 0;
}