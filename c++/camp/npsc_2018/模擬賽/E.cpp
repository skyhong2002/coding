
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath
//AC

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int tl, x, y, s, l;
	cin >> tl >> x >> y;

	l = tl / x - 1;

	if (tl % x < y && tl >= y){
		tl = tl - tl % x;
	}
	else{
		l = l + 1;
	}

	if(l < 0) l = 0;
	s =  tl - (y * l);


	cout << s << " " << l << endl;

    return 0;
}