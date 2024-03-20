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
        int n, d = INT_MAX, ans = -1;
        cin >> n;
        string s;
        cin >> s;
        vector<int> nums(n + 1, 0);
        for (int i = 1; i <= n; i++)
            nums[i] = nums[i - 1] + (s[i - 1] - '0');

        for (int i = 0; i <= n; i++)
        {
            int z = i - nums[i];
            int o = nums[n] - nums[i];
            int zero = ceil(i / 2.0);
            int one = ceil((n - i) / 2.0);
            if (z >= zero && o >= one)
            {
                int diff = abs(n / 2.0 - i);
                if (diff < d)
                {
                    d = diff;
                    ans = i;
                }
            }
        }
        cout << (ans == -1 ? 0 : ans) << endl;
    }
    return 0;
}