#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        map<int, vector<int>> mp;

        for (int &i : v)
            mp[i / 4].push_back(i);

        for (auto &val : mp)
            sort(val.second.rbegin(), val.second.rend());

        for (int &i : v)
        {
            cout << mp[i / 4].back() << ' ';
            mp[i / 4].pop_back();
        }
        cout << '\n';
    }
    return 0;
}