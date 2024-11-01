#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        int mini = min({x, y, k});

        cout << "0 0 " << mini << " " << mini << '\n';
        cout << mini << " 0 0 " << mini << '\n';
    }
    return 0;
}
