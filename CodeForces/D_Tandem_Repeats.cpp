#include <bits/stdc++.h>
using namespace std;
void solution()
{
    string s;
    int n, i, j, ans = 0;
    cin >> s;
    n = s.length();
    for (i = 1; i * 2 <= n; i++)
    {
        vector<int> preSum(n + 1, 0);
        for (j = 0; i + j < n; j++)
        {
            if (s[j] == s[i + j] || s[j] == '?' || s[i + j] == '?')
                preSum[j + 1] = preSum[j] + 1;
            else
                preSum[j + 1] = preSum[j];
        }
        for (j = 0; j <= n - i; j++)
        {
            if (preSum[i + j] - preSum[j] == i)
                ans = max(ans, i * 2);
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
