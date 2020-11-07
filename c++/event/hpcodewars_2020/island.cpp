#include <bits/stdc++.h>
using namespace std;

bool m[5][5];
bool tag[5][5];

void check(int i, int j)
{
    if (i < 0 || j < 0)
        return;
    if (i > 4 || j > 4)
        return;
    if (!tag[i][j] && m[i][j])
    {
        tag[i][j] = true;
        check(i + 1, j);
        check(i - 1, j);
        check(i, j + 1);
        check(i, j - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> m[i][j];
            tag[i][j] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (m[i][j] && !tag[i][j])
            {
                ans++;
                check(i, j);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
