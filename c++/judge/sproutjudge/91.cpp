
//單次AC的啦

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, pcnt;
	long long num;
	int p[30];
	cin >> cnt;
	for(int i = 0; i < cnt; i++)
	{
		pcnt = 0;
		memset(p, 0, sizeof(p));
		cin >> num;
		if(num == 1)
		{
			p[0] = 1;
			pcnt = 1;
		}
		for(int j = 9; j > 1; j--)
		{
			while(num%j == 0 && j <= num)
			{
				p[pcnt] = j;
				pcnt++;
				num = num/j;
				//cout << j << " x 1\n";
			}
		}
		if(num != 1)
		{
			cout << "-1\n";
			continue;
		}
		for(int j = pcnt - 1; j >= 0; j--)
		{
			cout << p[j];
		}
		cout << "\n";
		
	}

    return 0;
}