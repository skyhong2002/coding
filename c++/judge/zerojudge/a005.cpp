
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int cnt, a[5];

	cin >> cnt;

	for(int i = 0; i < cnt; ++i){

		cin >> a[0] >> a[1] >> a[2] >> a[3];

		if(a[1] - a[0] == a[2] - a[1]){
			cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[3] + a[2] - a[1] << "\n";
		}
		else{
			cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[3] * a[2] / a[1] << "\n";
		}
	}

    return 0;
}