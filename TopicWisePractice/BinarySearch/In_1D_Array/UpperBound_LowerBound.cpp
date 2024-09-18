#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

class Solution
{
public:
    // Function to find the floor of x
    int findFloor(vector<int> &v, int n, int x)
    {
        if (v[0] > x)
            return -1;

        int lo = 0, hi = n;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] > x)
                hi = mid;
            else
                lo = mid;
        }
        return v[lo]; // Returns the floor value
    }

    // Function to find the ceiling of x
    int findCeil(vector<int> &arr, int n, int x)
    {
        if (arr.back() < x)
            return -1;

        int lo = -1, hi = arr.size() - 1;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < x)
                lo = mid;
            else
                hi = mid;
        }
        return arr[hi]; // Returns the ceiling value
    }

    // Function to get both floor and ceiling
    vector<int> getFloorAndCeil(int x, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());           // Sort the array before searching
        int fX = findFloor(arr, arr.size(), x); // Find floor
        int cX = findCeil(arr, arr.size(), x);  // Find ceiling
        return {fX, cX};                        // Return floor and ceiling as a vector
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 8, 5, 3, 12, 9};
    int x = 7;

    vector<int> result = sol.getFloorAndCeil(x, arr);

    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

    return 0;
}
