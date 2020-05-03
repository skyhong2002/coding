//AC

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a[7];
	int box;

	while(1){

		cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
		box = 0;

		//6 x 1
		box += a[6];
		a[6] = 0;

		//5 x 1 + 11 x 1
		box += a[5];
		a[1] -= a[5]*11;
		a[5] = 0;
		
		//4 x 1 + 2 x 5
		box += a[4];
		a[2] -= a[4]*5;
		a[4] = 0;
		
		//3 x 4
		box += a[3] / 4;
		a[3] -= (a[3] / 4)*4;

		//3 x ? + 2 x ? + 1 x ?

		if(a[3] == 3){
			a[2] -= 1;
			a[1] -= 5;
		}
		else if(a[3] == 2){
			a[2] -= 3;
			a[1] -= 6;
		}
		else if(a[3] == 1){
			a[2] -= 5;
			a[1] -= 7;
		}

		if(a[3] > 0) box += 1;
		a[3] = 0;

		//2 x 9
		if(a[2] > 0){
			box += a[2] / 9;
			a[2] -= (a[2] / 9)*9;
		}

		if(a[1] < 0) a[1] = 0; //記得這行
		a[1] += a[2] * 4;
		a[2] = 0;

		//1 x 36
		if(a[1] > 0){
			box += a[1] / 36;
			a[1] -= (a[1] / 36)*36;

			if(a[1] > 0){
				box += 1;
				a[1] -= 36;
			}
		}

		if(box == 0) break;
		cout << box << "\n";
		
	}

    return 0;
}