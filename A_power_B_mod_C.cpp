#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_PRIME = 100000;
vector<int> primes;

// Function to generate primes up to MAX_PRIME using Sieve of Eratosthenes
void generate_primes()
{
    vector<bool> is_prime(MAX_PRIME + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_PRIME; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX_PRIME; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX_PRIME; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

// Function to check if there are three distinct primes whose squares sum up to N
bool check_sum_of_squares(int N)
{
    int size = primes.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            for (int k = j + 1; k < size; ++k)
            {
                long long sum_of_squares = 1LL * primes[i] * primes[i] +
                                           1LL * primes[j] * primes[j] +
                                           1LL * primes[k] * primes[k];
                if (sum_of_squares == N)
                {
                    return true;
                }
                if (sum_of_squares > N)
                {
                    break; // No point in continuing if the sum exceeds N
                }
            }
        }
    }
    return false;
}

int main()
{
    generate_primes();
    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        if (check_sum_of_squares(N))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
