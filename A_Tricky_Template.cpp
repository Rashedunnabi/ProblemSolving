#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solution()
{
    int n, i;
    cin >> n;

    string a, b, c;
    cin >> a >> b >> c;
    for (i = 0; i < n; i++)
    {
        if (a[i] != c[i] && b[i] != c[i])
        {
            yes;
            return;
        }
    }
    no;
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