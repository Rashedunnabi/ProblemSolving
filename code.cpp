#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    string smallestWindow(string s, string p)
    {
        map<char, int> mp;
        int j = 0, cnt = 0, window = INT_MAX, index = INT_MAX, k = p.length();

        for (int i = 0; i < (int)p.length(); i++)
        {
            mp[p[i]]++;
            if (mp[p[i]] == 1)
                cnt++;
        }
        for (int i = 0; i < k; i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    cnt--;
            }
        }
        if (cnt == 0)
            window = k, index = 0;

        for (int i = k; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    cnt--;
            }
            if (cnt == 0)
            {
                if (window > i - j + 1)
                {
                    window = i - j + 1;
                    index = max(0, j - 1);
                }
            }
        }

        if (window == INT_MAX)
            return "-1";

        cout << index << ' ' << window << '\n';

        string ss;
        for (int i = index; i < index + window; i++)
            ss.push_back(s[i]);
        return ss;
    }
};

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        string s, p;
        cin >> s >> p;
        Solution ob;
        cout << ob.smallestWindow(s, p) << '\n';
    }
    return 0;
}