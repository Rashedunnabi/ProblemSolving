#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        string s;
        cin >> n >> s;

        set<char> st;
        for (i = 0; i < n; i++)
            st.insert(s[i]);

        vector<char> v(st.begin(), st.end());
        map<char, char> mp;
        int sz = v.size();

        for (i = 0; i <= (sz / 2); i++)
        {
            char ch1 = v[i];
            char ch2 = v[sz - i - 1];

            mp[ch1] = ch2;
            mp[ch2] = ch1;
        }

        for (i = 0; i < n; i++)
        {
            cout << mp[s[i]];
        }
        cout << '\n';
    }
    return 0;
}