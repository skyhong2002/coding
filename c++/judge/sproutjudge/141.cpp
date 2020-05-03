//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int num[100005], dp[100005][2];
int cnt, numcnt, ans;

int solve(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];
	else if(j == 0) dp[i][j] = max(solve(i-1, 0), solve(i-1, 1));
	else if(j == 1) dp[i][j] = solve(i-1, 0) + num[i];
	//cout << "dp: " << i << " " << j << " = " << dp[i][j] << "\n";
	return dp[i][j];
}

void init(){
	for (int s = 1; s <= numcnt; s++) dp[s][0] = dp[s][1] = -1;
	dp[1][0] = 0;
	dp[1][1] = num[1];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> numcnt;
		for (int j = 1; j <= numcnt; j++) cin >> num[j];
		init();

		ans = max(solve(numcnt, 0), solve(numcnt, 1));
		cout << ans << "\n";
	}
    return 0;
}

/*
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int cnt, numcnt, num[100005], dp[100005];

int solve(int i){
	if(dp[i] != 0) return dp[i];
	dp[i] = max(solve(i-3), solve(i-2)) + num[i];

	//cout << "dp " << i << " = " << dp[i] << "\n";
	return dp[i];
}

void init(){
	for (int c = 1; c <= numcnt; c++) dp[c] = 0;
	
	dp[1] = num[1];
	dp[2] = num[2];
	dp[3] = num[1] + num[3];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int ans;

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> numcnt;
		for (int j = 1; j <= numcnt; j++) cin >> num[j];

		init();
		
		ans = max(solve(numcnt), solve(numcnt-1));
		cout << ans << "\n";

	}

    return 0;
}
*/