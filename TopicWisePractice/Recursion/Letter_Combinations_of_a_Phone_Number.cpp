#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int index, map<int, string> &mp, vector<string> &ans, string &str, string &s)
    {
        if (s.length() == str.length())
        {
            ans.push_back(s);
            return;
        }

        int x = str[index] - '0';
        string ss = mp[x];
        for (char ch : ss)
        {
            s.push_back(ch);
            func(index + 1, mp, ans, str, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string str)
    {
        if (str.length() == 0)
            return {};
        map<int, string> mp;
        mp[2] = "abc", mp[3] = "def";
        mp[4] = "ghi", mp[5] = "jkl";
        mp[6] = "mn0", mp[7] = "pqrs";
        mp[8] = "tuv", mp[9] = "wxyz";
        vector<string> ans;
        string s;
        func(0, mp, ans, str, s);
        return ans;
    }
};

int main()
{

    string s;
    cin >> s;
    Solution ob;
    auto v = ob.letterCombinations(s);
    for (auto val : v)
        cout << val << ' ';
    cout << '\n';

    return 0;
}