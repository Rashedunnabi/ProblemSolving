#include <bits/stdc++.h>
using namespace std;
#define int long long

string pat = "narek";
set<char> check = {'n', 'a', 'r', 'e', 'k'};

pair<int, int> func(string s, vector<int> &without, int index)
{
    int n = s.length(), j = 0, men = 0, gpt = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (check.find(ch) == check.end())
            continue;
        gpt++;
        if (s[i] == pat[j % 5])
        {
            if (s[i] == 'k')
            {
                men += 5;
                gpt -= 5;
                cur = gpt;
            }
            j++;
        }
    }
    without[index] = gpt - cur;
    return {men, gpt};
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        vector<string> v(n);
        for (auto &i : v)
            cin >> i;

        vector<pair<int, int>> vp(n);
        vector<int> without(n);
        for (int i = 0; i < n; i++)
            vp[i] = func(v[i], without, i);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vp[i].first > vp[i].second - without[i])
            {
                int x = vp[i].first - vp[i].second;
                ans = max(ans + x, ans + x - without[i]);
            }
        }
        cout << max(0LL, ans) << '\n';
    }
    return 0;
}