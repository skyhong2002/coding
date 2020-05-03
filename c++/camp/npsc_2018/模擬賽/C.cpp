
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath
//AC

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int x, a, b;
	cin >> x;

	if (x > 1000){
		a = 1000;
		b = x-1000;
	}
	else if(x > 0){
		a = x - 1;
		b = 1;
	}
	else{
		a = 0;
		b = 0;
	}

	cout << a << " " << b << "\n";

    return 0;
}