#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool canMakeAllOnes(string &str, int k)
{
    string s = str;
    int i, n = s.length();
    for (i = 0; i + k <= n; i++)
    {
        if (s[i] == '1')
            continue;
        for (int j = 0; j < k; j++)
        {
            if (s[i + j] == '0')
                s[i + j] = '1';
            else
                s[i + j] = '0';
        }
        // cout << s << ' ';
    }

    // cout << s << ' ' << k << endl;
    int cnt = count(s.begin(), s.end(), '1');
    return cnt == n;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = count(s.begin(), s.end(), '0');
        if (cnt == n)
        {
            cout << cnt << '\n';
            continue;
        }

        int left = 1, right = n;
        int ans = 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canMakeAllOnes(s, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}