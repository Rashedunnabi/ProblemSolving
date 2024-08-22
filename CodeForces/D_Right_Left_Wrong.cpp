#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        vector<int> v(n), preSum(n + 1), left, right;
        for (int &i : v)
            cin >> i;

        cin >> s;
        for (int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] + v[i];

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'L')
                left.push_back(i);
            else
                right.push_back(i);
        }
        reverse(right.begin(), right.end());
        int max_score = 0LL;
        int i = 0, j = 0, t = left.size(), m = right.size();

        while (i < t && j < m && left[i] < right[j])
            max_score += preSum[right[j++] + 1] - preSum[left[i++]];

        cout << max_score << "\n";
    }
    return 0;
}