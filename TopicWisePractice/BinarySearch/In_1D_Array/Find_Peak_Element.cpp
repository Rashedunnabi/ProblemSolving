#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        // Handle edge cases
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int lo = 1, hi = n - 2; // Start from 1 and end at n-2 to avoid boundary issues
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] < nums[mid + 1])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1; // This line should not be reached for valid inputs
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 20, 4, 1, 0};

    int result = sol.findPeakElement(nums);
    cout << "The peak element is at index: " << result << endl;

    return 0;
}
