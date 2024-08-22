#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        set<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (i + 1 < s.length() && s[i] == s[i + 1])
                i++;
            else
                st.insert(s[i]);
        }
        for (auto val : st)
            cout << val;
        cout << '\n';
    }
    return 0;
}