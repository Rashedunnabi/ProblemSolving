
// way1
#include <bits/stdc++.h>
using namespace std;
#define Rashed ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    Rashed;
    ll n;
    cin >> n;
    ll ans = 0;
    while (n > 0)
    {
        n /= 5;
        ans += n;
    }
    cout << ans << "\n";
    return 0;
}

// // way2
// #include <bits/stdc++.h>
// using namespace std;
// #define Rashed ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// #define ll long long

// int main()
// {
//     Rashed;
//     ll n;
//     cin >> n;
//     ll ans = 0;

//     for (int i = 1; i < 32; i++)
//     {
//         ans += (n / pow(5, i));
//     }
//     cout << ans << "\n";
//     return 0;
// }