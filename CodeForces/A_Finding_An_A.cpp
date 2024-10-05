#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    int id = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' && id == -1)
            id = i;
    }
    cout << s.substr(id) << '\n';
    return 0;
}