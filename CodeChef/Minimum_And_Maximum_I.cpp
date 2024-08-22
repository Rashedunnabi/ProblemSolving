#include <iostream>
using namespace std;

#define ll long long

void solution()
{
    ll n;
    cin >> n;

    ll sum = 0;
    if (n % 2 == 0)
    {
        n = n / 2;
        sum = n * (n + 1);
        cout << sum << '\n';
    }
    else
    {
        n = n / 2;
        sum = n * (n + 1) + n + 1;
        cout << sum << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
