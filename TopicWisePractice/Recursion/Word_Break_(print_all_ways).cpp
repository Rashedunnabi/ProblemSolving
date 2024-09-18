#include <bits/stdc++.h>
using namespace std;
void func(string &s, set<string> &dictionary, vector<string> &result, string current, int start)
{
    if (start == s.length())
    {
        result.push_back(current);
        return;
    }
    for (int i = start; i < s.length(); i++)
    {
        string word = s.substr(start, i - start + 1);
        if (dictionary.find(word) != dictionary.end())
        {
            string tmp = current.empty() ? word : current + " " + word;
            func(s, dictionary, result, tmp, i + 1);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    set<string> dict(dictionary.begin(), dictionary.end());
    vector<string> result;
    func(s, dict, result, "", 0);
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ar(n);
        for (auto &i : ar)
            cin >> i;
        string s;
        cin >> s;
        auto v = wordBreak(s, ar);
        for (auto val : v)
            cout << val << '\n';
        cout << '\n';
    }
}