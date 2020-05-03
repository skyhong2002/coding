
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath
//MLE

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int N, M;
	int upper_bound, lower_bound; //檢索範圍

	cin >> N >> M;
	upper_bound = N; //最後
	lower_bound = 1; //最前

	int ac_num[(N+1)]={0}; // 第i名的人答對幾題
	for(int i = 1; i<=N; i++){
		ac_num[i] = -1;
	}
	ac_num[0] = M;
	int ac_data[(M+1)]={0}; // 答對i題以下的有幾個人

	//找答題數最多的
	cout << 1 << '\n' << flush;
	cin >> ac_num[1];

	//找答題數最少的
	cout << N << '\n' << flush;
	cin >> ac_num[N];

	for(int i = ac_num[N]; i <= ac_num[1]; i++) // 從最少題到最多題開始找
	{
		while(ac_num[upper_bound] - ac_num[upper_bound-1] >= 0)
		{
			if(ac_num[(upper_bound + lower_bound) / 2] == -1){
				cout << (upper_bound + lower_bound) / 2 << '\n' << flush;
				cin >> ac_num[(upper_bound + lower_bound) / 2];
			}
			if(ac_num[(upper_bound + lower_bound) / 2] != ac_num[upper_bound]) lower_bound = (upper_bound + lower_bound) / 2;
			else upper_bound = (upper_bound + lower_bound) / 2;
		}
		ac_data[i] = N - lower_bound;
		upper_bound = lower_bound;
		lower_bound = 1;
	}

	for(int i = ac_num[1]; i <= M; i++) ac_data[i] = N;
	
	//找完了
	cout << "0\n";
	cout << ac_data[0] << '\n';
	for (int i = 1; i <= M; i++) {
		cout << ac_data[i] - ac_data[i-1] << '\n';
	}

    return 0;
}