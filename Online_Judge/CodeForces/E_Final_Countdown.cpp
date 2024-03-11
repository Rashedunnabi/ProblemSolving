#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void solution()
{
    string s;
    int n, i, carry = 0, sum = 0;
    cin >> n >> s;

    vector<int> ans(n), v;
    for (i = 0; i < n; i++)
    {
        sum += (s[i] - '0');
        ans[i] = sum;
    }

    reverse(all(ans));

    for (i = 0; i < n; i++)
    {
        int val = carry + ans[i];
        v.push_back(val % 10);
        carry = val / 10;
    }

    while (carry)
    {
        v.push_back(carry % 10);
        carry /= 10;
    }

    while (v.back() == 0)
        v.pop_back();

    reverse(all(v));

    for (int &e : v)
        cout << e;
    cout << '\n';
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