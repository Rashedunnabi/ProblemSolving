#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &nums)
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
        // Return the index of the minimum element which is the rotation count
        return nums[lo] < nums[hi] ? lo : hi;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int result = sol.findKRotation(nums);
    cout << "The number of rotations is: " << result << endl;

    return 0;
}
