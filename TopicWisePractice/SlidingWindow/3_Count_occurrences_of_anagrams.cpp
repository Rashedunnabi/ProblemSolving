#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(string pat, string txt)
    {
        int i, k = pat.length(), n = txt.size(), ans = 0, cnt = 0;
        map<char, int> mp;
        for (i = 0; i < k; i++)
            mp[pat[i]]++;

        cnt = mp.size();
        for (i = 0; i < k; i++)
        {
            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]--;
                if (mp[txt[i]] == 0)
                    cnt--;
            }
        }
        if (cnt == 0)
            ans++;

        for (i = k; i < n; i++)
        {
            // add the forword element in the window
            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]--;
                if (mp[txt[i]] == 0)
                    cnt--;
            }
            // remove the backword element in the window
            if (mp.find(txt[i - k]) != mp.end())
            {
                mp[txt[i - k]]++;
                if (mp[txt[i - k]] == 1)
                    cnt++;
            }
            if (cnt == 0)
                ans++;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string txt, pat;
        cin >> txt >> pat;
        Solution obj;
        cout << obj.search(pat, txt) << '\n';
    }
    return 0;
}