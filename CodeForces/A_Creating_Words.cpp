#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string t, s;
        cin >> t >> s;
        swap(t[0], s[0]);
        cout << t << " " << s << '\n';
    }
    return 0;
}