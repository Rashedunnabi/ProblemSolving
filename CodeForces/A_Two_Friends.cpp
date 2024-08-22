#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
void solution()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    map<int, int> mp;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        mp[i + 1] = v[i];
        if (mp[v[i]] == i + 1)
        {
            cout << 2 << '\n';
            return;
        }
    }
    cout << 3 << '\n';
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