
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

//https://neoj.sprout.tw/problem/74/

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long cnt, brickscnt, nowbrick, bricks[2];
	long long downcnt, slope;
	cin >> cnt;

	for(int i = 0; i < cnt; i++)
	{
		cin >> brickscnt;
		downcnt = 0;
		slope = 0;
		if(brickscnt <= 2){
			cin >> nowbrick;
			if(brickscnt == 2) cin >> nowbrick;
			cout << "0\n";
			continue;
		}

		cin >> nowbrick;
		bricks[1] = nowbrick;
		brickscnt --;
		
		while(brickscnt != 0)
		{
			bricks[0] = bricks[1];
			cin >> nowbrick;
			brickscnt --;
			bricks[1] = nowbrick;

			if(bricks[1] < bricks[0])
			{
				slope = -1;
			}
			
			if(bricks[1] > bricks[0] && slope == -1)
			{
				slope = 1;
				downcnt += 1;
			}
		}
		
		cout << (downcnt * 2 + 1) << "\n";

	}
	
    return 0;
}