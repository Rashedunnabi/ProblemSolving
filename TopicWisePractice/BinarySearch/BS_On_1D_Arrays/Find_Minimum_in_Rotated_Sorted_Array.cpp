#include <iostream>
#include <vector>
#include <algorithm> // For min function
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1, mid;
        while (hi - lo > 1)
        {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi])
                lo = mid + 1; // Minimum is in the right half
            else
                hi = mid; // Minimum is in the left half
        }
        return min(nums[lo], nums[hi]); // Return the minimum of the two candidates
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int result = sol.findMin(nums);
    cout << "The minimum element in the rotated sorted array is: " << result << endl;

    return 0;
}
