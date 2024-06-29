#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    while (1)
    {
        if (n == 1)
        {
            cout << 1 << "\n";
            break;
        }

        if (n & 1)
        {
            cout << n << " ";
            n = (n * 3) + 1;
        }
        else
        {
            cout << n << " ";
            n /= 2;
        }
    }
    return 0;
}