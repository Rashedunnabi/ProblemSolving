#include <iostream>
using namespace std;

int floorSqrt(int n)
{
    if (n == 0 || n == 1)
        return n; // Edge cases

    int lo = 1, hi = n, mid, ans = 1;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2; // Prevent overflow
        if (mid <= n / mid)       // Check if mid is a valid square root
        {
            ans = mid;    // Update result
            lo = mid + 1; // Search in the right half
        }
        else
            hi = mid - 1; // Search in the left half
    }
    return ans; // Return the largest integer whose square is <= n
}

int main()
{
    int n = 10; // Example input
    cout << "The floor of the square root of " << n << " is: " << floorSqrt(n) << endl;
    return 0;
}
