#pragma GCC optimise("O3", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int cnt;
	cin >> cnt;
	int N[cnt];
	
	for(int i = 0; i<cnt; i++){
		cin >> N[i];
	}
	
	int a, b, c, d, e;
	
	a = N[0] + N[2];
	b = N[1] + N[3];
	c = N[0] + N[3];
	d = N[0] + N[1] + N[3];
	e = N[0] + N[2] + N[3];
	
	int max = a;
	
	if(cnt=3){
		cout << max << "\n";
	}
	
	if(max < b)max = b;
	if(max < c)max = c;
	if(max < d)max = d;
	if(max < e)max = e;
	
	if(cnt=4){
		cout << max << "\n";
	}
	
}


