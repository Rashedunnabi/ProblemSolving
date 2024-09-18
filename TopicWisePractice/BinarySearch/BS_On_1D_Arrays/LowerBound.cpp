#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findFloor(vector<long long> &v, long long n, long long x)
    {
        if (v[0] > x)
            return -1; // If the smallest element is greater than x, return -1.

        long long lo = 0, hi = n;
        while (hi - lo > 1)
        {
            long long mid = lo + (hi - lo) / 2;
            if (v[mid] > x)
            {
                hi = mid; // If v[mid] is greater than x, search in the left half.
            }
            else
            {
                lo = mid; // Otherwise, search in the right half.
            }
        }
        return lo; // Return the index of the floor element.
    }
};

int main()
{
    Solution sol;
    vector<long long> v = {1, 2, 4, 6, 8, 10, 12};
    long long n = v.size();
    long long x = 9;

    int result = sol.findFloor(v, n, x);

    if (result != -1)
    {
        cout << "The floor of " << x << " is " << v[result] << " at index " << result << "." << endl;
    }
    else
    {
        cout << "No floor found for " << x << "." << endl;
    }

    return 0;
}
