#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> path;
    int tmp;
    bool ans = true;
    while (cin >> tmp)
    {
        path.emplace_back(tmp);
    }
    //cout << "OK\n";
    for (int i = 1; i < path.size(); i++)
    {
        ans = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (path[j] - (i - j) >= 0)
            {
                ans = true;
                break;
            }
        }
        if (!ans)
            break;
    }

    if (ans)
    {
        cout << "True\n";
    }
    else
        cout << "False\n";

    return 0;
}
