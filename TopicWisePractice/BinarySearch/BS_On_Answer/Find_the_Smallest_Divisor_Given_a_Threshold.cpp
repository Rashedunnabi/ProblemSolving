#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int lo = 1;                                          // start from 1 because divisor cannot be 0
        int hi = *max_element(nums.begin(), nums.end()) + 1; // +1 to ensure coverage of the maximum element

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            int result = 0;
            for (auto it : nums)
            {
                result += (it + mid - 1) / mid; // Equivalent to ceil(it / mid)
            }

            if (result <= threshold)
            {
                hi = mid; // try to find a smaller divisor
            }
            else
            {
                lo = mid + 1; // increase the divisor
            }
        }

        return lo; // Return the smallest valid divisor
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << "Smallest divisor is: " << sol.smallestDivisor(nums, threshold) << endl;
    return 0;
}
