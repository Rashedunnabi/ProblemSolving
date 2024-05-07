#include <bits/stdc++.h>
using namespace std;
#define int long long
struct asst
{
    int t, z, y;
};

int countMaxBalloons(int t, int z, int y, int Time)
{
    int batchTime = (z * t) + y;
    int batchCount = (Time / batchTime);
    int remTime = Time % batchTime;
    int totalBalloons = 0;
    totalBalloons += (batchCount * z);
    if (remTime != 0)
    {
        if (remTime / t >= z)
        {
            totalBalloons += z;
        }
        else
        {
            totalBalloons += (remTime / t);
        }
    }
    return totalBalloons;
}

bool isBalloonPossible(int t, int z, int y, int balloons, int Time)
{
    int batchTime = (z * t) + y;
    int batches = balloons / z;
    bool ok = (balloons % z == 0) ? 1 : 0;
    int currTime = 0;
    if (ok)
    {
        batches -= 1;
        currTime = (batchTime * batches) + (z * t);
    }
    else
    {
        currTime = (batchTime * (batches)) + ((balloons % z) * t);
    }
    return (currTime <= Time);
}

bool isPossible(asst *assistant, int n, int m, int Time)
{
    int totalBalloons = 0;
    for (int i = 0; i < n; i++)
    {
        int t = assistant[i].t;
        int z = assistant[i].z;
        int y = assistant[i].y;
        int lo = 0, hi = (int)1e9;
        while (hi > lo + 1)
        {
            int balloons = (lo + hi) >> 1;
            if (isBalloonPossible(t, z, y, balloons, Time))
            {
                lo = balloons;
            }
            else
            {
                hi = balloons;
            }
        }
        totalBalloons += lo;
    }
    return (totalBalloons >= m);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int m, n;
    cin >> m >> n;
    asst assistant[n];
    for (int i = 0; i < n; i++)
    {
        cin >> assistant[i].t >> assistant[i].z >> assistant[i].y;
    }
    int minTime = -1, maxTime = (int)1e9;
    while (maxTime > minTime + 1)
    {
        int Time = (minTime + maxTime) >> 1;
        if (isPossible(assistant, n, m, Time))
        {
            maxTime = Time;
        }
        else
        {
            minTime = Time;
        }
    }
    cout << maxTime << '\n';
    int count[n];
    memset(count, 0, sizeof count);
    for (int i = 0; i < n; i++)
    {
        int t = assistant[i].t;
        int z = assistant[i].z;
        int y = assistant[i].y;
        count[i] = countMaxBalloons(t, z, y, maxTime);
    }
    int totalBalloons = 0;
    for (int i = 0; i < n; i++)
    {
        if (totalBalloons + count[i] <= m)
        {
            cout << count[i] << " ";
            totalBalloons += count[i];
        }
        else
        {
            if (totalBalloons == m)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << (m - totalBalloons) << " ";
                totalBalloons = m;
            }
        }
    }
    cout << '\n';

    return 0;
}