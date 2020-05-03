
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

//AC in once

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int cnt, head, tail, step;
	cin >> cnt;

	for(int i = 0; i < cnt; i++)
	{
		step = 0;
		cin >> head >> tail;
		while(head!=0 or tail != 0){
			
			if (tail % 2 != 0) {
				tail += 1;
				step += 1;
			}

			while(tail > 0){
				tail -= 2;
				head += 1;
				step += 1;
			}			

			
			if (head % 2 != 0) {
				head += 1;
				step += 3;
			}
			

			while(head > 1){
				head -= 2;
				step += 1;
			}
			
		}

	cout << step << "\n";

	}

    return 0;
}