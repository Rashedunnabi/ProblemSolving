#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    // #define all(v) v.begin(), v.end()
    // #define all(v) v.begin(), v.end()
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());

    for (auto val : v)
        cout << val << ' ';
    cout << '\n';

    return 0;
}