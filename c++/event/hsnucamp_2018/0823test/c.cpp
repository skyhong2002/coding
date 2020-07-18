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
	int a0, b0, c0;
	long n;
	int a[MAXA], b[MAXA], c[MAXA], s[MAXA];
	s[0] = 0;

	//cout << "OK\n";

	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> n >> a0 >> b0 >> c0;

		n = n % 15;
		
		a[0] = a0; 
		b[0] = b0; 
		c[0] = c0;

		//cout << "j n a b c" << endl;

		for (int j = 1; j < n+1; ++j)
		{
			a[j] = 4 * a[j-1] - 3 * b[j-1] - 3 * c[j-1];
			b[j] = 5 * a[j-1] - 4 * b[j-1] - 4 * c[j-1];
			c[j] = b[j-1] - a[j-1];

			s[j] = s[j-1] + a[j] + b[j] + c[j];
			//cout << j << " " << (s[j] % 10 + 10) % 10 << " " << (a[j] % 10 + 10) % 10 << " " << (b[j] % 10 + 10) % 10 << " " << (c[j] % 10 + 10) % 10 << endl;
		}

		cout << (s[n] % 10 + 10) % 10 << endl;

	}

    return 0;
}