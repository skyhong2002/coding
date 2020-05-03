//AC

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int dp[100005][3];//[存到第幾格/2][上一個是不是都橫的]

//			--			--	        ||
//if == 0,  -- if == 1, || if == 2, ||
//			--			||	        --

int solve(int i, int j){
	if(dp[i][j] != 0) return dp[i][j];

	if(j == 0){
		dp[i][0] = (solve(i-1,0) + solve(i-1,1) + solve(i-1,2)) % 1000007;
	}
	else if(j == 1){
		dp[i][1] = (solve(i-1,0) + 2*solve(i-1,1) + solve(i-1,2)) % 1000007;
	}
	else if(j == 2){
		dp[i][2] = (solve(i-1,0) + solve(i-1,1) + 2*solve(i-1,2)) % 1000007;
	}

	return dp[i][j];
}

void init(){
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
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

		if(num % 2 == 0) ans = (solve(num/2, 0) + solve(num/2, 1) + solve(num/2, 2)) % 1000007;
		else ans = 0;

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

int dp[100005][3];  ///dp[存到第幾格][下面那格有沒有額外凸出來]

void init(){
	//初始狀態
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[2][0] = 2;
	dp[2][1] = 2;
}

int solve(int a, int b){
	if(dp[a][b] != 0 || a == 0) return dp[a][b];
	
	//狀態轉移
	if(b == 0) dp[a][b] = (2 * solve(a-2, 1) + solve(a-1, 0) + solve(a-2, 0)) % 1000007;
	else if(b == 1) dp[a][b] = (solve(a-1, 1) + solve(a-1, 0)) % 1000007;
	return dp[a][b];
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
		ans = 0;
		cin >> num;

		ans = solve(num, 0);
		cout << ans << "\n";
	}

    return 0;
}

*/