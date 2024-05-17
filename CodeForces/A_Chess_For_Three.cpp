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
        int ar[3];
        cin >> ar[0] >> ar[1] >> ar[2];

        int ans = 0;
        while (1)
        {
            sort(ar, ar + 3);
            if (ar[2] > 0 && ar[0] > 0)
            {
                ans++;
                ar[2]--, ar[0]--;
            }
            if (ar[2] > 0 && ar[1] > 0)
            {
                ans++;
                ar[2]--, ar[1]--;
            }
            if (ar[0] == 0 && ar[1] == 0)
                break;
        }
        sort(ar, ar + 3);
        if (ar[2] & 1)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}