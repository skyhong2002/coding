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
	long a, b, n;
	cin >> a >> b >> n;

	if(n%2 == 1) n = int(max(a*2, b) / min(a*2, b));
	else n = int(max(a, b) / min(a, b));


	cout << n << endl;
    return 0;
}
