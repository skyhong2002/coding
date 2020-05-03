
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimise("O3", "unroll-loops")d
#include <bits/stdc++.h>

using namespace std;

void proverb(int);

void proverb(int k){
	for(int i = 0; i < k; i++) cout << "Live and learn.\n";
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int cnt;
	
	while(cin >> cnt){
		proverb(cnt);
	}

    return 0;
}