#include <bits/stdc++.h>
using namespace std;

int query(string s)
{
    int x;
    cout << "? " << s << endl;
    cin >> x;
    return x;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;

        while (s.length() < n)
        {
            if (query(s + '0'))
                s += '0';
            else if (query(s + '1'))
                s += '1';
            else
                break;
        }
        while (s.length() < n)
        {
            if (query('0' + s))
                s = '0' + s;
            else
                s = '1' + s;
        }
        cout << "! " << s << endl;
    }
    return 0;
}