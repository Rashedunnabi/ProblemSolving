#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        string vowel = "aeiou";
        for (int i = 0; i < n; i++)
            s += vowel[i % 5];
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
    return 0;
}