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
        int n, m;
        cin >> n >> m;
        if (m > n)
        {
            no;
            continue;
        }
        int dif = m - n;
        if (dif & 1)
            no;
        else
            yes;
    }
    return 0;
}