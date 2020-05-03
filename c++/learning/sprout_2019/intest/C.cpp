#pragma GCC optimise("O3", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int cnt;
	cin >> cnt;
	int num[cnt], vre[cnt];
	
	for(int i = 0; i < cnt; i++){
		cin >> num[i];
		vre[i] = num[i];
		//cout << num[i] << " ";
	}
	
	//cout << "\n";
	
	int zipcnt = 0;
	int zipcntvre = 1;
	
	if(vre[1] - vre[0] > 0){
		vre[1] = min(vre[0], vre[2]) - 1;
	}
	else if(vre[1] - vre[0] > 0){
		vre[1] = max(vre[0], vre[2]) + 1;
	}
	else{
		if(num[1] > num[2]){
			num[0] = num[1] + 1;
			vre[0] = vre[1] - 1;
		}
		else{
			num[0] = num[1] - 1;
			vre[0] = vre[1] + 1;
		}
		zipcnt += 1;
	}
	
	for(int a = 1; a < cnt - 2; a++){
		
		if(num[a] >= num[a-1] && num[a] <= num[a+1]){
			num[a+1] = min(num[a], num[a+2]) - 1;
			zipcntvre++;
		}
		
		if(num[a] <= num[a-1] && num[a] >= num[a+1]){
			num[a+1] = max(num[a], num[a+2]) + 1;
			zipcntvre++;
		}
		
	}
	
	for(int a = 1; a < cnt - 2; a++){
		
		if(vre[a] >= vre[a-1] && vre[a] <= vre[a+1]){
			vre[a+1] = min(vre[a], vre[a+2]) - 1;
			zipcnt++;
		}
		
		if(vre[a] <= vre[a-1] && vre[a] >= vre[a+1]){
			vre[a+1] = max(vre[a], vre[a+2]) + 1;
			zipcnt++;
		}
		
	}
	
	
	cout << min(zipcnt, zipcntvre) << "\n";
	
}


