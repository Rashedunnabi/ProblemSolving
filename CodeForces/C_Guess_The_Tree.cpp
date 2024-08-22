#include <bits/stdc++.h>
using namespace std;

int get(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

void connect(int a, int b, vector<int> &visited, vector<pair<int, int>> &vp)
{
    int x = get(a, b);
    if (x == a)
    {
        vp.push_back({a, b});
        visited[a] = visited[b] = 1;
        return;
    }

    if (visited[a] && visited[x])
        connect(x, b, visited, vp);

    else
    {
        connect(a, x, visited, vp);
        connect(x, b, visited, vp);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> vp;
        vector<int> visited(n + 2);

        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (!visited[j])
                {
                    connect(i, j, visited, vp);
                }
            }
        }

        cout << "! ";
        for (auto val : vp)
            cout << val.first << ' ' << val.second << ' ';
        cout << endl;
    }
}