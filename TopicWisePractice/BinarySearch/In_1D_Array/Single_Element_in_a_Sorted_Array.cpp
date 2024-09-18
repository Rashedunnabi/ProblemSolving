#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1)
        {
            int mid = (hi + lo + 1) / 2;
            if (mid & 1)
                mid--; // Ensure mid is even
            if (nums[mid] == nums[mid + 1])
                lo = mid + 1; // The single element is in the right half
            else
                hi = mid; // The single element is in the left half
        }
        return nums[hi]; // Return the single non-duplicate element
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    int result = sol.singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}
