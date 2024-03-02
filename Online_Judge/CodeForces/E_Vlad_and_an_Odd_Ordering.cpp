#include <iostream>
#include <cmath>
using namespace std;

long long kthCard(long long n, long long k)
{
    long long odd_count = (n + 1) / 2;
    if (k <= odd_count)
    {
        // kth card is an odd number
        return 2 * (k - 1) + 1;
    }
    else
    {
        k -= odd_count;
        long long remaining_odd_multiples = (n - odd_count) / 2;
        long long group = (k + remaining_odd_multiples - 1) / remaining_odd_multiples;
        long long odd_multiple = 2 * group + 1;
        return odd_multiple * ((k - 1) % remaining_odd_multiples) + 2 * (group - 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << kthCard(n, k) << endl;
    }
    return 0;
}
