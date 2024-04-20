#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, ans = 1;
        string s;
        cin >> n >> s;
        for (int k = 2; k <= n; k++)
        {
            vector<int> v(n + 3);
            int cnt = 0;
            for (i = 0; i <= n - k; i++)
            {
                if ((cnt + s[i] - '0') % 2 == 0)
                {
                    cnt++;
                    v[i + k - 1] = 1;
                }
                cnt -= v[i];
            }
            bool flag = true;
            for (; i < n; i++) // i = n - k + 1
            {
                if ((cnt + s[i] - '0') % 2 == 0)
                {
                    flag = false;
                }
                cnt -= v[i];
            }
            if (flag)
                ans = k;
        }
        cout << ans << '\n';
    }
    return 0;
}