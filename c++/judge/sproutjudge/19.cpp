
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
	int cnt, num, goal, success, max;
	stack<int> s;

	cin >> cnt;

	for(int j = 0; j < cnt; j++){

		success = 1;
		num = 1;
		cin >> max;
	
		for(int i = 0; i < max; i++)
		{

			cin >> goal;

			if(num <= goal)
			{
				while(num < goal)
				{
					s.push(num);
					num++;
				}

				num++;

			}
			else if (s.top() == goal)
			{
				s.pop();
			}
			else
			{
				success = 0;
			}
				
		}

		if (success) {
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
		
	}
	
    return 0;
}