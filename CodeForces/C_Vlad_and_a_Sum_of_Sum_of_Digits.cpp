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

vector<ll> pre;
void func()
{
    ll temp, sum = 0;
    for (ll i = 1; i <= N; i++)
    {
        temp = i;
        while (temp != 0)
        {
            sum += temp % 10;
            temp = temp / 10;
        }
        pre.push_back(sum);
    }
}

void solution()
{
    int n;
    cin >> n;
    cout << pre[n - 1] << '\n';
}

int main()
{
    Faster;
    func();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}