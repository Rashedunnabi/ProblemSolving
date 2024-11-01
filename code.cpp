#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(int a, int b)
{
    int x;
    cout << "? " << a << ' ' << b << '\n';
    cin >> x;
    return x;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);

        vector<int> graph[n + 1];
        graph[0].push_back(1);
        graph[1].push_back(0);

        int leftPre = 1, rightPre = 0;
        for (int index = 2; index < n; index++)
        {
            int flag = query(1, index);
            if (flag)
            {
                graph[rightPre].push_back(index);
                graph[index].push_back(rightPre);
                rightPre = index;
            }
            else
            {
                graph[leftPre].push_back(index);
                graph[index].push_back(leftPre);
                leftPre = index;
            }
        }

        // while (index < n)
        // {
        //     graph[leftPre].push_back(index);
        //     graph[index].push_back(leftPre);
        //     leftPre = index++;

        //     if (index == n)
        //         break;

        //     graph[rightPre].push_back(index);
        //     graph[index].push_back(rightPre);
        //     rightPre = index++;

        //     if (index == n)
        //         break;
        // }

        for (int i = 0; i < n; i++)
        {
            cout << i << " : ";
            for (auto vv : graph[i])
                cout << vv << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}