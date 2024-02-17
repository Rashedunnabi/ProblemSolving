#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    int n, m, i, ans = 0, c = 0;
    cin >> n >> m;

    vector<int> v;
    string s;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        ans += s.length();
        while (s.length() && s.back() == '0')
            c++, s.pop_back();
        v.push_back(c), c = 0;
    }

    sort(v.rbegin(), v.rend());
    for (i = 0; i < v.size(); i += 2)
        ans -= v[i];

    if (ans > m)
        cout << "Sasha\n";
    else
        cout << "Anna\n";
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