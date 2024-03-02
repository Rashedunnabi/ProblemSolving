#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x, i, ans, p, q, j, p2, q2;
string s, day;

bool check(ll p)
{
    if (p % 400 == 0)
    {
        return 1;
    }
    else if (p % 100 == 0)
    {
        return 0;
    }
    else if (p % 4 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
ll monthDay(ll month, ll year)
{
    if (month == 2)
    {
        if (check(year))
            return 29;
        else
            return 28;
    }
    set<ll> st = {1, 3, 5, 7, 8, 10, 12};
    if (st.find(month) != st.end())
        return 31;
    else
        return 30;
}

void calenderPrint(ll daysInMonth, string day, ll date)
{
    map<string, ll> mp;
    mp["Sun"] = 1, mp["Mon"] = 2;
    mp["Tue"] = 3, mp["Wed"] = 4;
    mp["Thu"] = 5, mp["Fri"] = 6;
    mp["Sat"] = 7;

    ll arr[5][7];

    ll c = 1, n = 5, m = 7, st = 0, flag = 1, k = 0;
    while (k < 7)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                arr[i][j] = 0;

        c = 1;
        ll temp = st;
        for (i = 0; i < n; i++)
        {
            if (i > 0)
                temp = 0;
            for (j = temp; j < m; j++)
            {
                if (c > daysInMonth)
                    continue;
                arr[i][j] = c++;

                if (arr[i][j] == date && j == mp[day] - 1)
                {
                    // cout << "hi" << '\n';
                    flag = 0;
                }
            }
        }
        if (!flag)
            break;
        k++, st++;
    }

    if (arr[n - 1][j - 1] != daysInMonth)
    {
        ll sz = daysInMonth - c;
        for (j = 0; j <= sz; j++)
            arr[0][j] = c++;
    }

    if (date == 31 && day == "Sun")
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                arr[i][j] = 0;

        arr[0][0] = 31, arr[0][5] = 1, arr[0][6] = 2;

        c = 3;
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (c > daysInMonth)
                    continue;
                arr[i][j] = c++;
            }
        }
    }

    cout << "|---------------------------|" << '\n';
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|" << '\n';
    cout << "|---------------------------|" << '\n';

    for (i = 0; i < n; i++)
    {
        cout << "|";
        for (j = 0; j < m; j++)
        {
            if (arr[i][j])
            {
                if (arr[i][j] < 10)
                    cout << "  ";
                else
                    cout << " ";
                cout << arr[i][j] << "|";
            }
            else
            {
                cout << " - |";
            }
        }
        cout << '\n';
        cout << "|---------------------------|" << '\n';
    }
    cout << '\n';
}

void solve()
{
    cin >> s >> day;
    string a = "", b = "", c = "";
    a += s[0], a += s[1];                       // days
    b += s[3], b += s[4];                       // month
    c += s[6], c += s[7], c += s[8], c += s[9]; // year
    ll date = stol(a);
    ll month = stol(b);
    ll year = stol(c);

    ll daysOfMonth = monthDay(month, year);
    calenderPrint(daysOfMonth, day, date);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(0);

    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}