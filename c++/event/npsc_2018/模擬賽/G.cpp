
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by 陳楚融
//AC

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 5;
const LL INF = 1e11;
LL arr[N], sum[N], dp[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for (int i = 1;i <= n; i++) cin >> arr[i];
	LL cnt = 0, mm = -INF;
	for (int i = 1; i <= n; i ++){
		cnt += arr[i];
		mm = max(cnt, mm);
		if (cnt < 0) cnt = 0;
		sum[i] = mm;
	}
	dp[0] = -INF; dp[1] = -INF; dp[2] = -INF;
	LL mx = -INF;
	for(int i = 3; i <= n; i ++){
		dp[i] = max(mx + arr[i], sum[i-2] + arr[i]);
		mx = max(mx, dp[i]);
	}
	LL ans = -INF;
	for (int i = 1; i <= n; i ++) ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}