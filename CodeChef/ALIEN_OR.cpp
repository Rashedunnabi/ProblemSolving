#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

string binary(int n)
{
    string s(n, '0');
    s[0] = '1';

    return s;
}
void solution()
{
    int n, k, i;
    cin >> n >> k;
    set<string> st;
    for (i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        while (s.back() == '0')
            s.pop_back();

        reverse(s.begin(), s.end());
        if (s.size())
            st.insert(s);
    }
    for (i = 0; i < k; i++)
    {
        if (st.find(binary(i + 1)) == st.end())
        {
            no;
            return;
        }
    }
    yes;
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
