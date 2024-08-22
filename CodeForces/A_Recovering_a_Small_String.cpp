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
    int n;
    cin >> n;

    char f, s, t;

    f = 'a', s = 'a', t = 'a';

    for (int i = 4; i <= n; i++)
    {
        if (t == 'z')
        {
            if (s == 'z' && f != 'z')
            {
                f++;
            }
            else
            {
                s++;
            }
        }
        else
        {
            t++;
        }
    }
    cout << f << s << t << endl;
}

int main()
{
    Faster;
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
