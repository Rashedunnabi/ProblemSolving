#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solution()
{
    int n, i;
    cin >> n;
    deque<int> q;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }
    sort(q.rbegin(), q.rend());
    int x = q.back();
    q.push_front(x);
    q.pop_back();

    vector<int> v(q.begin(), q.end());

    ll sum = 0ll;
    for (i = 0; i < n - 1; i++)
    {
        sum += v[i] + v[i + 1];
    }
    cout << sum << '\n';
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