//AC in 3 days

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int numcnt, Cnt, ans = 0;
long long A[1000005]; //記得開TMD long long 搞死我耶
long long B[1000005];

int counting(int Left, int Right){

	//cout << "counting " << Left << " to " << Right << "\n";

	if(Left + 1 == Right) return 0;//長度為1, 終止條件
	
	int Mid = (Left + Right) / 2; //找出中間的位置
	int Cnt = 0;

	Cnt += counting(Left, Mid); //A[Left]~A[Mid-1]
	Cnt += counting(Mid, Right); //A[Mid]~A[Right-1]

	//cout << "counting " << Left << " to " << Right << " Start.\n";

	int L = Left;//左箭頭的起點永遠在左邊
	int R = Mid; //右箭頭的起點永遠在中間
	int Rcnt = 0;

	for(L = Left; L < Mid; L++){ //枚舉

		while(R < Right && A[R] < A[L]){
			//cout << "Founded " << A[L] << " > " << A[R] << ".\n";
			Rcnt = (Rcnt + A[R]) % 10000019;
			R++;
		}
		ans = (ans + Rcnt + (R - Mid) * (A[L] % 10000019)) % 10000019;
		Cnt += R - Mid;
	}

	//for(int i = 0; i < numcnt; i++) cout << A[i] << " ";
	//cout << "\n";

	//cout << "counting " << Left << " to " << Right << " enumerated, Start sorting.\n";
	
	//Merge sort

	int K=Left;
	L=Left;
	R=Mid;

	while(L < Mid || R < Right)
		if( L < Mid && (R >= Right || A[L] <= A[R]) ){
			B[K] = A[L];
			//cout << A[L] << " ";
			K++; L++;
		}
		else{
			B[K] = A[R];
			//cout << A[R] << " ";
			K++; R++;
		}

	for(L=Left; L<Right; L++) A[L]=B[L];

	//cout << "counting " << Left << " to " << Right << " sorted.\n";
	//for(int i = 0; i < numcnt; i++) cout << A[i] << " ";
	//cout << "\n";

	//cout << "ans = " << ans << "\n";

	return Cnt;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> numcnt;

	for(int i = 0; i < numcnt; i++) cin >> A[i];

	counting(0, numcnt);

	cout << ans << "\n";

    return 0;
}


