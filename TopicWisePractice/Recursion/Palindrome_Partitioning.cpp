#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(string &s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }

    void func(int index, string &s, vector<string> &v, vector<vector<string>> &ans)
    {
        if (index == s.length())
        {
            ans.push_back(v);
            return;
        }

        for (int i = index; i < s.length(); i++)
        {
            string ss = s.substr(index, i - index + 1);
            if (check(ss))
            {
                v.push_back(ss);
                func(i + 1, s, v, ans);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> v;
        func(0, s, v, ans);
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution ob;
    auto it = ob.partition(s);
    for (auto v : it)
    {
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    cout << '\n';
    return 0;
}