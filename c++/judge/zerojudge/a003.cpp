
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int m, d, s;
	while(cin >> m >> d){
		s = ( m * 2 + d ) % 3;
		if (s == 0)
		{
			cout << "普通\n";
		}
		else if(s == 1){
			cout << "吉\n";
		}
		else{
			cout << "大吉\n";
		}
	}
	
    return 0;
}