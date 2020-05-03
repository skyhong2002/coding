
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath


//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>


long long N, n[4294967298], ans, V, num;

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> num;
		n[num] += 1;
	}
	cin >> V;

	if(V < 0 || V > 2000000){
		cout << "0\n";
		return 0;
	}

	for(int i = 1; i < V; i++){
		if(i > V - i)break;
		if(i == V - i) ans += n[i] * (n[V-i]-1) / 2;
		else ans += n[i] * n[V-i];
		//cout << i << ": " << n[i] << ", " << V-i << ": " << n[V-i] << "; = " << ans << "\n";
	}	
	
	cout << ans;

    return 0;
}
