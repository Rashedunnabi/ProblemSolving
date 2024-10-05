#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int tc = 0; tc <= t; tc++)
    {
        string s;
        getline(cin, s);
        if (tc == 0)
            continue;
        set<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch <= 'z' && ch >= 'a')
                st.insert(ch);
            if (ch <= 'Z' && ch >= 'A')
            {
                ch = ch - 'A' + 'a';
                st.insert(ch);
            }
        }
        if (st.size() == 26)
            cout << "pangram\n";
        else
        {
            cout << "missing ";
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (st.find(ch) == st.end())
                    cout << ch;
            }
            cout << '\n';
        }
    }
    return 0;
}