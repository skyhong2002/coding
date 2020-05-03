//TLE

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int h[1000000];
int main() {
	int MAXA = 99999, MAXN = 100000007;
	int cnt;
	long catcnt;
	long ch;
	long hcnt;
	

	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		cin >> catcnt;

		for (long j = 0; j < catcnt; ++j)
		{
			cin >> ch;
			h[j] = ch;

			hcnt = 0;

			for (long k = j - 1; k >= 0; --k)
			{
				if(h[k] < ch) hcnt += 1;
				else break;

			}
			cout << hcnt << " ";
		}
		cout << endl;
	}


    return 0;
}
