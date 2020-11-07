#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char in;
    vector<int> a, b, ans;

    while (cin >> in)
    {
        if (in == '[')
            continue;
        else if (in == ',')
            continue;
        else if (in == ']')
            break;
        a.emplace_back(in - '0');
    }

    while (cin >> in)
    {
        if (in == '[')
            continue;
        else if (in == ',')
            continue;
        else if (in == ']')
            break;
        b.emplace_back(in - '0');
    }
    int tmp = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++)
    {
        ans.emplace_back(a[i] + b[i] + tmp);
        tmp = ans[i] / 10;
        ans[i] = (ans[i] + 10) % 10;
    }

    if (tmp != 0)
        ans.emplace_back(tmp);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    return 0;
}
