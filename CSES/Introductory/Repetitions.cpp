#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans = 1, c = 1;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            c++, ans = max(ans, c);
        else
            ans = max(ans, c), c = 1;
    }
    cout << ans << endl;
    return 0;
}