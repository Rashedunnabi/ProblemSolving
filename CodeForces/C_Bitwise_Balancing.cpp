#include <bits/stdc++.h>
using namespace std;
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int b, c, d, num = 0, flag = 1;
        cin >> b >> c >> d;

        for (int i = 0; i <= 62; i++)
        {
            int x = (CheckBit(b, i) != 0);
            int y = (CheckBit(c, i) != 0);
            int z = (CheckBit(d, i) != 0);

            if ((x == 0 && y == 1 && z == 1) || (x == 1 && y == 0 && z == 0))
                flag = -1;
            if ((x == 0 && y == 0 && z == 1) || (x == 1 && y == 1 && z == 0))
                SetBit(num, i);
        }
        cout << (flag == -1 ? flag : num) << '\n';
    }
    return 0;
}