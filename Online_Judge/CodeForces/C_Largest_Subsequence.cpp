#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(v) v.begin(), v.end()

void solution()
{
    int n, i, cnt = 0;
    string s, temp, ss;
    cin >> n >> s;

    temp = s;
    sort(all(temp));

    pair<char, char> p;
    p.first = p.second = -1;

    for (i = 0; i < n; i++)
    {
        if (temp[i] != s[i])
        {
            char a, b;
            a = min(temp[i], s[i]);
            b = max(temp[i], s[i]);
            cout << a << " " << b << endl;

            if (p.first == a && p.second == b)
            {
                continue;
            }
            p.first = a;
            p.second = b;
            cnt++;
        }
    }

    for (i = 1; i < n; i++)
    {
        if (s[i] > s[0])
        {
            for (int j = 1; j < i; j++)
            {
                if (s[j] < s[0])
                {
                    cout << -1 << endl;
                    return;
                }
            }
            break;
        }
    }
    cout << cnt << endl;
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}