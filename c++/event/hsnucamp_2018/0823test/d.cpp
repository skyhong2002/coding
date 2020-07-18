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
	struct Dsu {
		vector<int> fa;

  		Dsu(int n) {
    		fa.assign(n, 0);
    		for (int i = 0; i < n; ++i) fa[i] = i;
  		}
  
		int find(int x) {
		  	return fa[x] == x ? x : fa[x] = find(fa[x]);
  		}
  
  		bool unite(int x, int y) {
    		if (find(x) == find(y)) return false;
    		return fa[find(x)] = find(y), true;
  		}
	};

	
	
	//cout << "Hello World!";
    return 0;
}