#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    getline(cin, str);
    stringstream ss(str);

    vector<int> A;

    for (int i; ss >> i;)
    {
        A.emplace_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    for (int i = 0; i < A.size(); i++)
    {
    }

    return 0;
}