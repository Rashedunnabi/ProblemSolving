#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    int n, c, i;
    cin >> n >> c;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    ll total = (c + 1) * 1LL * (c + 2) / 2;
    int even = 0, odd = 0;
    for (int &i : v)
    {
        (i & 1) ? odd++ : even++;
        total -= (1 + (i / 2));
        total -= (c - i + 1);

        total += (i & 1) ? odd : even;
    }
    cout << total << '\n';
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