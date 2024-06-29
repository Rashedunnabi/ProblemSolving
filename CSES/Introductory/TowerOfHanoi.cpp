#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, int src, int mid, int des)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, src, des, mid); // source to middle using destination
    cout << src << " " << des << endl;
    towerOfHanoi(n - 1, mid, src, des); // middle to destination using source
}

int main()
{
    int n, ans = 0;
    cin >> n;
    ans = pow(2, n) - 1;
    cout << ans << endl;

    towerOfHanoi(n, 1, 2, 3);

    return 0;
}