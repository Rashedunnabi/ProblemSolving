#include <bits/stdc++.h>
using namespace std;

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

        vector<char> v;
        v.push_back(s[0]);
        for (i = 1; i < n; i++)
        {
            if (v.back() != s[i])
                v.push_back(s[i]);
        }
        int zero = count(v.begin(), v.end(), '0');
        int one = count(v.begin(), v.end(), '1');
        cout << min(zero, one) << '\n';
    }
    return 0;
}