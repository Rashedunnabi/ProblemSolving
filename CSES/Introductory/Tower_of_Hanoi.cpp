#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, int l, int r, int mid)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, l, mid, r);
    cout << l << " " << r << endl;
    towerOfHanoi(n - 1, mid, r, l);
}

int main()
{
    int n, l, r, mid, ans = 0;
    cin >> n;
    ans = pow(2, n) - 1;
    cout << ans << endl;

    towerOfHanoi(n, 1, 3, 2);

    return 0;
}