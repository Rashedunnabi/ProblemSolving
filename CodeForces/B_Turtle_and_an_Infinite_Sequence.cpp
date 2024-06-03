#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))

int previousValue(int n, int ind)
{
    int i, tmp = n, lastOne = -1;
    for (i = 31; i >= ind; i--)
    {
        if (CheckBit(tmp, i))
            lastOne = i;
    }
    ClearBit(tmp, lastOne);
    for (int i = ind; i >= 0; i--)
        SetBit(tmp, i);

    return tmp;
}
int nextValue(int n, int ind)
{
    int tmp = n;
    SetBit(tmp, ind);
    for (int i = ind - 1; i >= 0; i--)
        ClearBit(tmp, i);

    return tmp;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 31; i >= 0; i--)
        {
            if (CheckBit(n, i))
                continue;

            int preVal = previousValue(n, i);
            int nextVal = nextValue(n, i);

            int mini = min(abs(preVal - n), abs(nextVal - n));
            if (mini <= m)
                SetBit(n, i);
        }
        cout << n << '\n';
    }
    return 0;
}