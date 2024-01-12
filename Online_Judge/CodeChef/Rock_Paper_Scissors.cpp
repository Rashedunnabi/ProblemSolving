#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    int n, i, j, val = 0, c = 0;
    cin >> n;
    string s, ans;
    cin >> s;

    val = 1 + n / 2;

    for (i = 0; i < n; i++)
    {
        // cout << n - i << ' ' << val << '\n';
        if (n - i > val)
        {
            if (s[i] == 'R')
                val--;

            s[i] = 'P';
        }
        else
        {
            if (s[i] == 'P')
                s[i] = 'S';
            else if (s[i] == 'R')
                s[i] = 'P';
            else
                s[i] = 'R';
        }
    }

    cout << s << '\n';
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