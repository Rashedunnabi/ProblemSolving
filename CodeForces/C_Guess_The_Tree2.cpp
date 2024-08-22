#include <bits/stdc++.h>
using namespace std;

int get(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> vp;
        for (int i = 1; i < n; i++)
        {
            int a = i, b = n;
            while (1)
            {
                int x = get(a, b);
                if (x == a)
                {
                    vp.push_back({a, b});
                    break;
                }
                b = x;
            }
        }

        cout << "! ";
        for (auto val : vp)
            cout << val.first << ' ' << val.second << ' ';
        cout << endl;
    }
}