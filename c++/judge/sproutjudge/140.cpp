
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int dp[100005][3][3]; //[有幾格][第一格是紅、綠、藍][最後一格是紅、綠、藍]

int solve(int i, int j, int k){
	if(dp[i][j][k] != -1) return dp[i][j][k];
	else if(k == 0) dp[i][j][k] = (solve(i-1, j, 0) + solve(i-1, j, 1) + solve(i-1, j, 2)) % 1000007;
	else if(k == 1) dp[i][j][k] = (solve(i-1, j, 0) + solve(i-1, j, 1)) % 1000007;
	else if(k == 2) dp[i][j][k] = (solve(i-1, j, 0) + solve(i-1, j, 2)) % 1000007;
	//cout << "dp " << i << " " << j << " " << k << " = " << dp[i][j][k] << "\n";
	return dp[i][j][k];
}

void init(){

	for (int s = 0; s < 100005; s++)
	{
		dp[s][0][0] = -1;
		dp[s][0][1] = -1;
		dp[s][0][2] = -1;
		dp[s][1][0] = -1;
		dp[s][1][1] = -1;
		dp[s][1][2] = -1;
		dp[s][2][0] = -1;
		dp[s][2][1] = -1;
		dp[s][2][2] = -1;
	}
	

	dp[1][0][0] = 1;
	dp[1][1][1] = 1;
	dp[1][2][2] = 1;

	dp[2][0][0] = 1;
	dp[2][0][1] = 1;
	dp[2][0][2] = 1;
	dp[2][1][0] = 1;
	dp[2][1][1] = 1;
	dp[2][1][2] = 0;
	dp[2][2][0] = 1;
	dp[2][2][1] = 0;
	dp[2][2][2] = 1;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int cnt, num, ans;

	init();

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		cin >> num;

		if(num == 1){
			cout << "3\n";
			continue;
		}

		ans =(solve(num, 0, 0)
			+ solve(num, 1, 0)
			+ solve(num, 2, 0)
			+ solve(num, 0, 1)
			+ solve(num, 0, 2)
			+ solve(num, 1, 1)
			+ solve(num, 2, 2))%1000007;

		cout << ans << "\n";
	}
	

	

    return 0;
}