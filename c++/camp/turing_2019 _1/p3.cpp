
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath


//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

long long N, ans, V, num;
map <long long, long long> n;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N;
	for (long long i = 0; i < N; i++){
		cin >> num;
		n[num] += 1;
	}
	cin >> V;

	if(V < 0 || V > 2000002 || N == 1){
		cout << "0\n";
		return 0;
	}

	for(long long i = 0; i <= V; i++){
		if(i > V - i) break;
		if(i == V - i) ans += n[i] * (n[V-i]-1) / 2;
		else ans += n[i] * n[V-i];
		//cout << i << ": " << n[i] << ", " << V-i << ": " << n[V-i] << "; = " << ans << "\n";
	}	
	
	cout << ans;

    return 0;
}

/*

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long N, n[1000005], ans,V;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> n[i];
	cin >> V;

	sort(n, n + N);
	for (int i = 0; i < N; i++) cout << n[i] << " ";
	cout << "\n";

	long long t;

	// 拿兩個
	for(int i = 0; i < N - 1; i++){
		if(n[i] + n[i+1] > V) break;
		for(int j = i + 1; j < N; j++){
			if(n[i] + n[j] == V){
				ans += 1;
			}
			if(n[i] + n[j] > V)continue;
		}
	}
	
	
	
	cout << ans;

    return 0;
}

*/