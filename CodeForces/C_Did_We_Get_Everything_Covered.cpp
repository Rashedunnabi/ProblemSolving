#include <bits/stdc++.h>
using namespace std;

#define yes cout << "YES\n"
#define no cout << "NO\n"

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s, ans;
        int i, n, k, m;
        cin >> n >> k >> m >> s;

        set<char> st;
        for (i = 0; i < m; i++)
        {
            st.insert(s[i]);
            if (st.size() == k)
            {
                ans.push_back(s[i]);
                st.clear();
            }
        }

        if (ans.length() >= n)
            yes;
        else
        {
            no;
            char ch = 'a';
            for (i = 0; i < k; i++)
            {
                if (st.find(ch) == st.end())
                {
                    break;
                }
                ch++;
            }

            while (ans.length() < n)
                ans.push_back(ch);
            cout << ans << '\n';
        }
    }
    return 0;
}