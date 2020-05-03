
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath
//資料來源https://blog.csdn.net/u014235934/article/details/50963777

#include <bits/stdc++.h>

using namespace std;

int n, m;
int G[100005][100005];
int color[100005];

bool bfs(int s)
{
	color[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int from = q.front();
		q.pop();
		for(int j = 0; j < n; j++)
		{
			if(color[j] == 0 && G[from][j] == 1)
			{
				q.push(j);
				color[j] = -color[from];
			}
			if(color[j] == color[from] && G[from][j] == 1)
			{
				return false;
			}
		}
		
	}
	return true;
}

int main() {

	bool ans;

	cin >> n;
	
	while(n != 0){

		cin >> m;

		//初始化
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				G[i][j] = 0;
			}
		}
		memset(color, 0, m);
		ans = true;
		

		for(int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			G[a][b] = 1;
			G[b][a] = 1;
		}
		/*
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << G[i][j] << " ";
			}
			cout << "\n";
		}
		*/
		for(int i = 0; i < n; i++)
		{
			if(color[i] == 0){
				if(bfs(i) == false){
					ans = false;
					break;
				}
			}
		}
		
		if(ans == true) cout << "NORMAL.\n";
		else if(ans == false) cout << "RAINBOW.\n";
		
		cin >> n;

	}

    return 0;
}