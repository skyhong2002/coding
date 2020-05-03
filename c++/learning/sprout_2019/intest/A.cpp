#pragma GCC optimise("O3", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int cnt, max;
	cin >> cnt;
	int flower[cnt];
	
	for(int i=0; i < cnt; i++){
		cin >> flower[i];
		if(flower[i] == cnt ){
			max = i;
			break;
		}
	}
	
	int ndmax = 0;
	int ndplace = 0;
	int kcnt= 0;
	
	for(int j=max-1; j>=0; j--){
		if(flower[j] > ndmax){
			ndmax = flower[j];
			ndplace = j;
		}
	}
	
	if(ndmax == 0){
		cout << "0\n";
	}
	else{
		kcnt = max - ndplace;
		cout << kcnt << "\n";
	}
	
	
	
}
