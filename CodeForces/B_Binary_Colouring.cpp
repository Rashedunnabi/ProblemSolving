#include <bits/stdc++.h>
using namespace std;
#define CheckBit(x, k) (x & (1LL << k))

vector<int> BinaryNumber(int n)
{
    int lg = __lg(n);
    vector<int> v;
    for (int i = lg; i >= 0; i--)
    {
        if (CheckBit(n, i))
            v.push_back(1);
        else
            v.push_back(0);
    }
    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        vector<int> v = BinaryNumber(num);
        int n = v.size(), i, pre = -1, oneCount = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] == 1)
            {
                if (pre == -1)
                    pre = i;
                else
                    v[i] = 0;
                oneCount++;
            }
            else
            {
                if (pre != -1 && oneCount > 1)
                {
                    v[pre] = -1;
                    v[i] = 1;
                    pre = i;
                    oneCount = 1;
                }
                else
                {
                    pre = -1;
                    oneCount = 0;
                }
            }
        }

        if (pre != -1 && oneCount > 1)
        {
            v[pre] = -1;
            v.push_back(1);
        }

        cout << v.size() << '\n';
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}