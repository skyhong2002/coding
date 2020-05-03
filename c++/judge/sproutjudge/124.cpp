
//單次AC的啦

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

//https://neoj.sprout.tw/problem/124/

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

void Report(int x1, int y1, int x2, int y2, int x3, int y3){

	cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";

	return;
}

void solve(int N, int x, int y, int sx = 0, int sy = 0){
	
	int quadrant;

	//橫軸為x, 縱軸為y
	//四大象限為N*N的四邊
	//確認多的那一塊在第幾象限
	if((x - sx) >  N / 2 && (y - sy) <= N / 2) quadrant = 1;
	if((x - sx) <= N / 2 && (y - sy) <= N / 2) quadrant = 2;
	if((x - sx) <= N / 2 && (y - sy) >  N / 2) quadrant = 3;
	if((x - sx) >  N / 2 && (y - sy) >  N / 2) quadrant = 4;

	if(quadrant == 1) Report(sx + N/2, sy + N/2    ,  sx + N/2    , sy + N/2 + 1,  sx + N/2 + 1, sy + N/2 + 1); //2, 3, 4
	if(quadrant == 2) Report(sx + N/2, sy + N/2 + 1,  sx + N/2 + 1, sy + N/2 + 1,  sx + N/2 + 1, sy + N/2    ); //3, 4, 1
	if(quadrant == 3) Report(sx + N/2, sy + N/2    ,  sx + N/2 + 1, sy + N/2 + 1,  sx + N/2 + 1, sy + N/2    ); //2, 4, 1
	if(quadrant == 4) Report(sx + N/2, sy + N/2    ,  sx + N/2    , sy + N/2 + 1,  sx + N/2 + 1, sy + N/2    ); //2, 3, 1

	if(N == 2) return;

	if(quadrant == 1) solve(N/2,  x       , y       ,  sx + N/2, sy + 0  );
	if(quadrant == 2) solve(N/2,  x       , y       ,  sx + 0  , sy + 0  );
	if(quadrant == 3) solve(N/2,  x       , y       ,  sx + 0  , sy + N/2);
	if(quadrant == 4) solve(N/2,  x       , y       ,  sx + N/2, sy + N/2);

	if(quadrant != 1) solve(N/2,  sx + N/2, sy + N/2,  sx + N/2, sy + 0  );
	if(quadrant != 2) solve(N/2,  sx + N/2, sy + N/2,  sx + 0  , sy + 0  );
	if(quadrant != 3) solve(N/2,  sx + N/2, sy + N/2,  sx + 0  , sy + N/2);
	if(quadrant != 4) solve(N/2,  sx + N/2, sy + N/2,  sx + N/2, sy + N/2);

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int inN, inx, iny;

	cin >> inN >> inx >> iny;

	solve(inN, inx, iny);

    return 0;
}