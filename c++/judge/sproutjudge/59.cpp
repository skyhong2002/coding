
//莫名AC

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int cnt, ord, num;
	priority_queue<int, vector<int>, greater<int> > pq;

	// 把 priority_queue<int> 改成 priority_queue<int, vector<int>, greater<int> > 就過了？？？
	//https://www.geeksforgeeks.org/implement-min-heap-using-stl/


	cin >> cnt;
	for(int i = 0; i < cnt; i++)
	{
		cin >> ord;
		if(ord == 1)
		{
			cin >> num;
			pq.push(num);
		}
		else if (ord == 2) {
			if(!pq.empty()){
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << "empty!\n";
			}
		}
		
	}

    return 0;
}

