// C++ program to generate all prime numbers
// less than N in O(N)
#include <bits/stdc++.h>
using namespace std;

// isPrime[] : isPrime[i] is true if number is prime
// prime[] : stores all prime number less than N
// spf[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put spf[8] = 2 , spf[16] = 2 ]
#define int long long
const int MAX_SIZE = 1000001;
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
    int N = 13;

    seive(N);

    for (int i = 0; i < prime.size() && prime[i] <= N; i++)
        cout << prime[i] << " ";

    return 0;
}
