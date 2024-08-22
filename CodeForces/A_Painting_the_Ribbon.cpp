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
        int n, m, k, val;
        cin >> n >> m >> k;

        val = (n + m - 1) / m;
        val = n - val;
        if (val > k)
            yes;
        else
            no;
    }
    return 0;
}