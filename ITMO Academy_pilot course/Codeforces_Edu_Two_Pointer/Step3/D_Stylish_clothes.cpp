#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> takeInput()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    return v;
}

int difference(int a, int b, int c, int d)
{
    return max({a, b, c, d}) - min({a, b, c, d});
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector<int> caps = takeInput();
    vector<int> pants = takeInput();
    vector<int> shirts = takeInput();
    vector<int> shoes = takeInput();

    int n1 = caps.size(), n2 = pants.size(), n3 = shirts.size(), n4 = shoes.size();
    int i1, i2, i3, i4, a, b, c, d, mini = LONG_LONG_MAX;
    i1 = i2 = i3 = i4 = a = b = c = d = 0;

    while (i1 < n1 && i2 < n2 && i3 < n3 && i4 < n4)
    {
        int dif = difference(caps[i1], pants[i2], shirts[i3], shoes[i4]);
        if (dif < mini)
        {
            mini = dif;
            a = i1, b = i2, c = i3, d = i4;
        }
        if (caps[i1] <= pants[i2] && caps[i1] <= shirts[i3] && caps[i1] <= shoes[i4])
            i1++;
        else if (pants[i2] <= caps[i1] && pants[i2] <= shirts[i3] && pants[i2] <= shoes[i4])
            i2++;
        else if (shirts[i3] <= caps[i1] && shirts[i3] <= pants[i2] && shirts[i3] <= shoes[i4])
            i3++;
        else if (shoes[i4] <= caps[i1] && shoes[i4] <= shirts[i3] && shoes[i4] <= shirts[i3])
            i4++;
    }
    cout << caps[a] << ' ' << pants[b] << ' ' << shirts[c] << ' ' << shoes[d] << '\n';

    return 0;
}