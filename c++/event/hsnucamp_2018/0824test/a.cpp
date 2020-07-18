//AC

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
	int MAXA = 99999, MAXN = 100000007;
	int cnt;
	int pay;
	int money;
	int bill;

	money = 0;
	bill = 0;

	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		cin >> pay;

		if(pay == 0) money += 1000;
		if(money != 0) bill += 100;
		//cout << i << " " << money << " " << bill << endl;
	}

	cout << (money + bill);
    return 0;
}
