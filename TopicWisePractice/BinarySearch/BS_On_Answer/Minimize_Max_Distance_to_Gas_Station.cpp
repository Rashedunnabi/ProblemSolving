#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, double mid, int m)
{
    int val = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        double dif = arr[i] - arr[i - 1];
        val += ceil(dif * 1.0 / mid) - 1;
    }
    return val <= m;
}

double minimiseMaxDistance(vector<int> &arr, int m)
{
    double lo = 0.0, esp = 1e-6;
    double hi = 0.0;
    for (int i = 1; i < arr.size(); i++)
        hi = max(hi, arr[i] - arr[i - 1] + 0.0);

    while (hi - lo > esp)
    {
        double mid = (hi + lo) / 2.0;
        if (check(arr, mid, m))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main()
{
    int n, m;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the number of allowed splits (m): ";
    cin >> m;

    double result = minimiseMaxDistance(arr, m);
    cout << fixed << setprecision(6) << "The minimized maximum distance is: " << result << endl;

    return 0;
}
