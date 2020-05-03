
//AC in once

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int cnt, act, num;

	cin >> cnt;
	queue<int> q;

	for(int i = 0; i < cnt; i++)
	{
		cin >> act;
		if (act == 1) {
			cin >> num;
			q.push(num);
		} else
		{
			if (q.empty()) {
				cout <<"empty!\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
			
			
		}
		
		
	}


    return 0;
}