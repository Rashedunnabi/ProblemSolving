#include <bits/stdc++.h>
using namespace std;

void generateAll(int open, int close, string &s, vector<string> &v)
{
    if (open == 0 && close == 0)
    {
        v.push_back(s);
        return;
    }
    if (open > 0)
    {
        s.push_back('(');
        generateAll(open - 1, close, s, v);
        s.pop_back();
    }
    if (close > open)
    {
        s.push_back(')');
        generateAll(open, close - 1, s, v);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> v;
    string s;
    int open = n, close = n;
    generateAll(open, close, s, v);
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v = generateParenthesis(n);
    for (auto val : v)
        cout << val << '\n';
    cout << '\n';
}