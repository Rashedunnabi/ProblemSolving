#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int ans = 1;
        vector<int> v(n);
        for (int k = 2; k <= n; k++)
        {
            fill(v.begin(), v.end(), 0);
            int cnt = 0;
            for (int i = 0; i <= n - k; i++)
            {
                if ((cnt + (s[i] - '0')) % 2 == 0)
                {
                    cnt ^= 1;
                    v[i + k - 1] = 1;
                }
                cnt ^= v[i];
            }
            int check = 1;
            for (int i = n - k + 1; i < n; i++)
            {
                check &= ((cnt + (s[i] - '0')) % 2 == 1);
                cnt ^= v[i];
            }
            if (check)
                ans = k;
        }
        cout << ans << "\n";
    }
    return 0;
}