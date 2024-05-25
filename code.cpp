#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    vector<pair<int, int>> vp;
    vp.push_back({2, 5});

    for (auto [u, v] : vp)
    {
        cout << u << ' ' << v << '\n';
    }
    return 0;
}