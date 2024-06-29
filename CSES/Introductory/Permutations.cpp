#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        for (i = 2; i <= n; i += 2)
            cout << i << " ";
        for (i = 1; i <= n; i += 2)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}