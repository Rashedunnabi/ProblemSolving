#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_SIZE = 100001;
vector<int> isprime(MAX_SIZE, true);
vector<int> prime;
vector<int> spf(MAX_SIZE);
void seive(int N)
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < N && prime[j] <= spf[i]; j++)
        {
            isprime[i * prime[j]] = false;
            spf[i * prime[j]] = prime[j];
        }
    }
}
// Time Complexity: O(N)

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;

    seive(MAX_SIZE);
    while (t--)
    {
        int n, flag = 0;
        cin >> n;
        n -= 4;

        for (int i = 0; i < (int)prime.size() && prime[i] < n; i++)
        {
            int val = n - (prime[i] * prime[i]);
            int b = sqrtl(val);

            if (isprime[b] && prime[i] != 2LL && prime[i] != b && b * b == val)
                flag = 1;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}