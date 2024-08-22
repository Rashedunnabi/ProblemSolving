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
        string s;
        cin >> s;

        string ss = s;
        sort(s.begin(), s.end());
        if (ss != s)
        {
            yes;
            cout << s << '\n';
        }
        else
        {
            reverse(s.begin(), s.end());
            if (ss != s)
            {
                yes;
                cout << s << '\n';
            }
            else
            {
                no;
            }
        }
    }
    return 0;
}