#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int main() {
	int MAXA = 99999, MAXN = 100000007;
	int mapN;

	cin >> mapN;

	int map[mapN+1][mapN+1];
	int MAXstep = mapN * 2 - 2;
	int dp[mapN*2][mapN+1][mapN+1];

	for (int i = 0; i < mapN+1; ++i)
	{
		map[i][0] = -MAXN;
		map[0][i] = -MAXN;
	}

	for (int i = 1; i < mapN+1; ++i)
	{
		for (int j = 1; j < mapN+1; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i < mapN+1; ++i)
	{
		for (int j = 1; j < mapN+1; ++j)
		{
			cin >> map[i][j];
		}
	}



	//cout << "Meow";
    return 0;
}