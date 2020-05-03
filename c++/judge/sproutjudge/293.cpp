
//AC Awfulsome和雅荺幫忙 耗時80min.

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int N;
int awful[100005];
int ans[100005];
vector<int> dot[100005];

int calculate(int x, int y){ //(自己, 父節點)

	int a;
	for(int i = 0; i < dot[x].size(); i++)
	{
		if(dot[x][i] != y){
			a = calculate(dot[x][i], x);
			awful[x] += a;
			ans[x] = max(ans[x], a);
		}
	}
	awful[x] += 1;

	ans[x] = max(ans[x], N - awful[x]);

	return awful[x];

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int T;

	cin >> T;

	for(int i = 0; i < T; i++)
	{

		cin >> N;
		int ans2 = N;

		for(int j = 0; j < N; j++) dot[j].clear();
		for(int j = 0; j < N; j++) awful[j] = 0;
		for(int j = 0; j < N; j++) ans[j] = 0;
		
		int a, b;
		for(int j = 0;j < N - 1;j++){
				cin >> a >> b;
				dot[a].push_back(b);
				dot[b].push_back(a);
		}

		//計算慘度

		calculate(0, N); //隨便抓一個點當root
		
		//ans

		for(int j = 0; j < N; j++){
			ans2 = min(ans[j], ans2);
		}


		int ans3 = 0;
		for(int j = 0; j < N; j++)
		{
			if(ans2 == ans[j]){
				ans3 = j;
				break;
			}
		}


		cout << ans3 << "\n";
		

	}
	

    return 0;
}