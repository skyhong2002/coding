
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by 陳楚融

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

map <char, int> number;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, bomb; cin >> n >> m >> bomb;
	int sl[n + 1][m + 1];
	char c;
	for (int i = 1; i < 10; i ++) number[char(i + '0')] = i;
	for (int i = 97; i < 97 + 26; i ++) number[char(i)] = i - 87;
	for (int i = 65; i < 65 + 26; i ++) number[char(i)] = i - 29;
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			cin >> c;
			sl[i][j] = number[c];
		}
	}
//	for (int i = 1; i <= n; i ++){
//		for (int j = 1; j <= m; j ++){
//			cout << sl[i][j] << endl;
//		}
//	}
	int x, y, r, ans = 0;
	for (; bomb > 0; bomb --){
		cin >> x >> y >> r;
		ans = 0;
		for (int i = 1; i <= n; i ++){
			for (int j = 1; j <= m; j ++){
				if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r){
					if (sl[i][j] > 0){
						sl[i][j] --;
						ans += 1;
					}
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}