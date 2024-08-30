#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int last)
{
    if (v.size() == 0 || v.back() < last)
    {
        v.push_back(last);
        return;
    }
    int val = v.back();
    v.pop_back();
    insert(v, last);
    v.push_back(val);
}

void sortArray(vector<int> &v)
{
    if (v.size() == 0)
        return;

    int last = v.back();
    v.pop_back();
    sortArray(v);
    insert(v, last);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    sortArray(v);
    for (auto val : v)
        cout << val << ' ';
    cout << '\n';
    return 0;
}