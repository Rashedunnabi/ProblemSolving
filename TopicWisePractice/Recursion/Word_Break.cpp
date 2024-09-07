#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, bool> mp;
    bool func(string s, vector<string> &ar)
    {
        if (s.size() == 0)
            return true;
        if (mp.find(s) != mp.end())
            return mp[s];
        for (string &word : ar)
        {
            string ss = s.substr(0, word.length());
            if (ss == word && func(s.substr(word.length()), ar))
                return mp[s] = true;
        }
        return mp[s] = false;
    }

    bool wordBreak(string s, vector<string> &ar)
    {
        return func(s, ar);
    }
};

int main()
{
    string s;
    int n;
    cin >> s >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    Solution ob;
    cout << ob.wordBreak(s, v) << '\n';
    return 0;
}