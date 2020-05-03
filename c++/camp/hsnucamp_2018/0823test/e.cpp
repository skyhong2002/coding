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


int main() {
	int cnt;
	long pluscnt;
	long num[100000007];
	long plus[100000007];

	cin >> cnt;
	cout << "Www";

	for (int i = 0; i < cnt; ++i)
	{
		cin >> num[i];
	}

	sort(num, num+cnt);
	pluscnt = 0;

	for (int i = 0; i < cnt; ++i)
	{
		for (int j = i + 1; j < cnt; ++j)
		{
			plus[pluscnt] = num[i] + num[j];
			pluscnt++;
		}
	}
	sort(plus, plus+pluscnt);

	cout << plus[pluscnt/2];

    return 0;
}