#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define PLL pair<ll, ll>
#define pii pair<int, int>
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define scn(n) scanf("%d", &n)
#define scnll(n) scanf("%lld", &n)
#define nl cout << "\n"
#define YES cout << "YES\n"
#define Yes cout << "Yes\n"
#define yes cout << "yes\n"
#define NO cout << "NO\n"
#define No cout << "No\n"
#define no cout << "no\n"
#define mod 1000000009LL
#define mod1 1000000007LL
#define mod2 1000000009LL
#define inf 1000000000000000LL
#define N 1000010
#define fastio                             \
    std::ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                         \
    cout.tie(NULL);
using namespace std;

int main()
{
    fastio;
    int t, ts = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        int inv[n + 2];
        int ans = 0;
        for (int i = n; i > 0; i--)
        {
            for (int j = 0; j <= n; j++)
            {
                inv[j] = 0;
            }
            int cnt = 0;
            for (int j = 0; j + i <= n; j++)
            {
                if ((cnt + s[j] - '0') % 2 == 0)
                {
                    inv[j + i - 1] = 1;
                    cnt++;
                }
                cnt -= inv[j];
            }
            bool is_possible = true;
            for (int j = n - i + 1; j < n; j++)
            {
                if ((cnt + s[j] - '0') % 2 == 0)
                {
                    is_possible = false;
                    break;
                }
                cnt -= inv[j];
            }
            if (is_possible)
            {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
}