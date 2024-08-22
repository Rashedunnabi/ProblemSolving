#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, q, i;
    cin >> n >> q;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    while (q--)
    {
        int x;
        cin >> x;
        cout << (upper_bound(v.begin(), v.end(), x) - v.begin()) << '\n';
    }
    return 0;
}