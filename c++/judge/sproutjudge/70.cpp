
//AC

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	long long cnt, num, ans, a, b;
	priority_queue<long long, vector<long long>, greater<long long> > pq; //記得開long long

	cin >> cnt;
	while(cnt != 0)
	{
		ans = 0;
		for(int i = 0; i < cnt; i++)
		{
			cin >> num;
			pq.push(num);
		}
		while(!pq.empty())
		{	
			a = pq.top();
			//cout << pq.top() << " ";
			pq.pop();
			b = pq.top();
			//cout << pq.top() << " ";
			pq.pop();
			ans = ans + a + b;
			//cout << a + b << "\n";
			if(pq.empty()) break;
			pq.push(a + b);
		}
		cout << ans << "\n";
		cin >> cnt;	//記得再次cin
	}

    return 0;
}

