#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solution()
{
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i + 1] || s[i] == '?' || s[i + 1] == '?')
        {
            ans = 1;
        }
    }

    for (int i = 2; i < n; ++i)
    {
        vector<int> v;
        for (int j = 0; j < n - i; ++j)
        {
            if (s[j] == s[j + i] || s[j] == '?' || s[j + i] == '?')
            {
                v.push_back(j);
            }
        }
        sort(v.begin(), v.end());

        int mx = 1;
        int cnt = 1;
        for (int j = 1; j < v.size(); ++j)
        {
            if (v[j] - 1 == v[j - 1])
            {
                cnt += 1;
            }
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
        if (mx >= i)
        {
            ans = max(ans, i);
        }
    }

    ans *= 2;
    cout << ans << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
