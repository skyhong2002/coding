//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by 陳楚融

//WA

#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

double dis(pair <double, double> &a, pair <double, double> &b){
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main(){

	int n; cin >> n;
	double ans;
	pair <double, double> p[n];
	for (int i = 0; i < n; i ++){
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 0; i < n - 1; i ++){
		for (int j = i + 1; j < n; j ++){
			ans += dis(p[i], p[j]) * double(n - 2);
		}
	}
	printf("%.10f", ans / n);

	return 0;
}
