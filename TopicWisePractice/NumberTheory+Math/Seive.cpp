#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
bool prime[N + 1];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}
// Time Complexity: O(N*log(log(N)))

int main()
{
    SieveOfEratosthenes();
    int n = 30;
    cout << prime[n] << '\n';
    return 0;
}
