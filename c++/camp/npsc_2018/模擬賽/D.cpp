
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by 陳楚融
//AC

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string res;
	int arr[1000];
	for (int i = 0; i < 1000; i ++) arr[i] = i + 1;
	int min = 1, max = 1000, mid = (min + max) / 2;
	cout << arr[mid - 1] << '\n';
	cout << flush;
	cin >> res;
	while (res != "correct"){
		if (res == "lower"){
			max = mid - 1;
		}
		else if (res == "higher"){
			min = mid + 1; 
		}
		mid = (min + max) / 2;
		cout << arr[mid - 1] << '\n';
		cout << flush;
		cin >> res;
	}

	return 0;
}