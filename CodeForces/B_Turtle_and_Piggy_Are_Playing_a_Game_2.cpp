#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        multiset<int> s;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        bool turn = true;
        while (s.size() > 1)
        {
            if (turn)
                s.erase(s.begin());
            else
                s.erase(s.find(*s.rbegin()));
            turn ^= 1;
        }
        cout << *s.begin() << '\n';
    }
    return 0;
}