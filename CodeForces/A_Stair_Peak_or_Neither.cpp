#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "STAIR\n"
#define no cout << "PEAK\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b > a && b < c)
            yes;
        else if (b > a && b > c)
            no;
        else
            cout << "NONE\n";
    }
    return 0;
}