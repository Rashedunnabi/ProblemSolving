#include <iostream>
#include <cmath>
using namespace std;

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;
        if (ans > m)
            return 2; // mid^n exceeds m
    }
    if (ans == m)
        return 1; // mid^n equals m
    return 0;     // mid^n is less than m
}

int NthRoot(int n, int m)
{
    if (m == 0 || m == 1)
        return m; // Handle edge cases
    int lo = 1, hi = m, ans = -1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        int val = func(mid, n, m);
        if (val == 1)
        {
            return mid; // Exact root found
        }
        if (val == 2)
        {
            hi = mid - 1; // mid^n is too large, reduce search range
        }
        else
        {
            lo = mid + 1; // mid^n is too small, increase search range
        }
    }
    return -1; // No integer root found
}

int main()
{
    int n = 3;  // Example input for n
    int m = 27; // Example input for m
    cout << "The " << n << "-th root of " << m << " is: " << NthRoot(n, m) << endl;
    return 0;
}
