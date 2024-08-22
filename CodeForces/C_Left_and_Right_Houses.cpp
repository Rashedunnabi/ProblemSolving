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
        int n, i;
        cin >> n >> s;

        s = '#' + s;
        int zero = 0, one = count(s.begin(), s.end(), '1'), minVal = INT_MAX, ans = -1;

        for (i = 0; i <= n; i++)
        {
            if (s[i] == '0')
                zero++;
            if (s[i] == '1')
                one--;

            int nZero = ceil(i / 2.0);
            int nOne = ceil((n - i) / 2.0);
            if (zero >= nZero && one >= nOne)
            {
                int val = abs(2 * i - n);
                cout << "for: " << i << " : ";
                cout << abs((n / 2) - i) << ' ' << abs((n / 2.0) - i) << '\n';
                if (val < minVal)
                {
                    minVal = val;
                    ans = i;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}