// Question is: update the  values of a segment L....R with X for Q time/queryes
// After all query's output the resultend Array
// PartialSum Technique

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    vector<int> partialSum(n + 2); // make a initial array that contain 0's only

    int q;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        // because we 0 based index,convert the given range in 0 based
        l--, r--;
        // Update l...R with values X
        partialSum[l] += x;
        partialSum[r + 1] -= x;
    }

    for (i = 1; i <= n; i++)
        partialSum[i] += partialSum[i - 1];
    for (i = 0; i < n; i++)
        partialSum[i] += v[i];

    for (i = 0; i < n; i++)
        cout << partialSum[i] << ' ';
    cout << '\n';
}