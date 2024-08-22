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
        int i, n;
        cin >> n;
        string s;
        cin >> s;
        int one = count(s.begin(), s.end(), '1');
        int dOne = 0;
        for (i = 0; i < n - 1; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1')
                dOne++, i++;
        }
        if (one && ((one == 2 && dOne == 1) || n <= 2 || one & 1))
            no;
        else
            yes;
    }
    return 0;
}