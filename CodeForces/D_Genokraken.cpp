#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        auto ask = [&](int a, int b)
        {
            cout << "? " << a << ' ' << b << endl;
            int x;
            cin >> x;
            return x;
        };

        vector<int> parent(n);
        int lo = 1;
        for (int i = 2; i < n; i++)
        {
            if (ask(lo, i))
            {
                if (lo == 1)
                    parent[i] = 0;
                else
                    lo++, i--;
            }
            else
                parent[i] = lo++;
        }
        cout << "! ";
        for (int i = 1; i < n; i++)
            cout << parent[i] << ' ';
        cout << '\n';
    }
    return 0;
}