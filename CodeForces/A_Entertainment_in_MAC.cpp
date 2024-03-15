#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solution()
{
    int n, i, j;
    cin >> n;
    string s;
    cin >> s;
    i = 0, j = s.length() - 1;

    while (s[i] == s[j] && i <= j && i < n)
    {
        i++;
        j--;
    }
    // cout << i << ' ' << j << '\n';

    if (n % 2 == 0)
    {
        if (s[i] <= s[j])
        {
            cout << s << '\n';
        }
        else
        {
            string ss = s;
            reverse(all(ss));
            cout << ss << s << '\n';
        }
    }
    else
    {
        if (s[i] <= s[j])
        {
            string ss = s;
            reverse(all(ss));
            cout << ss << s << '\n';
        }
        else
        {
            cout << s << '\n';
        }
    }
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