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
        int cnt = count(s.begin(), s.end(), 'U');
        cout << ((cnt & 1) ? "YES\n" : "NO\n");
    }
    return 0;
}