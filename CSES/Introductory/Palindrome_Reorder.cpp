#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, odd = 0;
    string s;
    cin >> s;
    n = s.length();

    string ss(n, '0');
    map<char, int> mp;
    for (i = 0; i < n; i++)
        mp[s[i]]++;

    for (auto val : mp)
        if (val.second & 1)
            odd++;

    if (n & 1 && odd > 1)
        cout << "NO SOLUTION\n";
    else if (n % 2 == 0 && odd > 0)
        cout << "NO SOLUTION\n";
    i = 0;

    char ch;
    for (auto val : mp)
    {
        if (val.second & 1)
        {
            ch = val.first;
            continue;
        }
        while (val.second)
        {
            ss[i] = ss[n - i - 1] = val.first;
            i++;
            val.second -= 2;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (ss[i] == '0')
            ss[i] = ch;
    }

    cout << ss << endl;

    return 0;
}