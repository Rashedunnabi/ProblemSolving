#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        string s, ans;
        cin >> n >> s;

        map<char, int> mp;
        for (int i = 0; i < n; i++)
            mp[s[i]]++;

        while (1)
        {
            if (mp.empty())
                break;
            vector<char> to_erase;
            for (auto &it : mp)
            {
                ans.push_back(it.first);
                it.second--;
                if (it.second == 0)
                    to_erase.push_back(it.first);
            }
            for (char ch : to_erase)
                mp.erase(ch);
        }
        cout << ans << '\n';
    }
    return 0;
}