#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "Sakurako\n"
#define no cout << "Kosuke\n"

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int startPos = 0, i = 1, turn = 1;
        while (abs(startPos) <= n)
        {
            int val = 2 * i - 1;
            if (turn & 1)
                startPos -= val;
            else
                startPos += val;
            // cout << startPos << ' ';
            turn++, i++;
        }
        if (turn & 1)
            no;
        else
            yes;
    }
    return 0;
}