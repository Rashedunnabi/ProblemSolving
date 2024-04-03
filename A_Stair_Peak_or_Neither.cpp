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
        int a, b, c;
        cin >> a >> b >> c;
        if (b > a && c > b)
            cout << "STAIR\n";
        else if (b > a && b > c)
            cout << "PEAK\n";
        else
            cout << "NONE\n";
    }
    return 0;
}