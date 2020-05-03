
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
	int cnt, act, num;

	cin >> cnt;
	stack<int> s;

	for(int i = 0; i < cnt; i++)
	{
		cin >> act;
		if (act == 1) {
			cin >> num;
			s.push(num);
		} else
		{
			if (s.empty()) {
				cout <<"empty!\n";
			}
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
			
			
		}
		
		
	}


    return 0;
}