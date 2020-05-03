//AC

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

// 1 11 4
// 3 1 4 1 5 9  2 6  5  3  5
// 3 1 4 1 8 12 6 10 13 15 17

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;
int num[1005], dp[1005]; //dp[總共有n個數字] = 在第n個之前的數字總和最大值。（在間隔gap之內且有取第n個值
int cnt, numcnt, gap, ans;

void solve(int i){ 
	for(int c = gap + 1; c <= i; c++){
		if(dp[c] != -1) continue;
		for(int d = c - gap; d > c - 2 * gap; d--){
			if(d <= 0) break;
			dp[c] = max(dp[c], dp[d]);
		}
		dp[c] += num[c];
		//cout << "dp " << c << " = " << dp[c] << "\n";
	}
	return;
}

void init(){
	
	for(int s = 1; s <= numcnt; s++) dp[s] = -1;

	for(int s = 1; s <= gap; s++) dp[s] = num[s];

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> numcnt >> gap;
		for (int j = 1; j <= numcnt; j++) cin >> num[j];

		init();
		solve(numcnt);
		ans = 0;
		for(int j = numcnt; j > numcnt - gap; j--) ans = max(ans, dp[j]);
		cout << ans << "\n";
			
	}

    return 0;
}