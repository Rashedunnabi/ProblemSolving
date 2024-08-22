#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, c;
    string s;
    cin >> n >> c >> s;

    int l = 0, ans = 0, cntA = 0, cntB = 0, sum = 0;
    for (int r = 0; r < n; ++r)
    {
        if (s[r] == 'a')
            cntA++;
        else if (s[r] == 'b')
        {
            sum += cntA;
            cntB++;
        }

        while (sum > c)
        {
            if (s[l] == 'a')
            {
                sum -= cntB;
                cntA--;
            }
            else if (s[l] == 'b')
                cntB--;

            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
