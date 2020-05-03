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

long long data[1000000];
int main() {
	int MAXA = 10000, MAXN = 100000007;
	int ncnt, mcnt, qcnt;
	int a, b;
	long long findata;
	int found;

	cin >> ncnt >> mcnt >> qcnt;

	

	for (int i = 0; i < mcnt; ++i)
	{
		cin >> a >> b;
		data[i] = a * 100000000 + b;
	}

	for (int i = 0; i < qcnt; ++i)
	{
		cin >> a >> b;
		findata = a * 100000000 + b;
		bool bo = true;

		for (int j = 0; j < mcnt; ++j)
		{
			if(findata == data[j]){
				bo = false;
				cout << "yes" << endl;
				break;
			}
		}
		if(bo) cout << "no" << endl;
	}

    return 0;
}
