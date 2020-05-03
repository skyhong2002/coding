
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int y;

	while(cin >> y){

		if (y%400 == 0 || y%4==0 && y%100!=0){
			cout << "閏年\n";
		}
		else{
			cout << "平年\n";
		}

	}

    return 0;
}