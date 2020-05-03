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


int MAXA = 1000000, MAXN = 0;
int cnt, pos;
int cget, wget, iff;
int c[MAXA], w[MAXA], iff[MAXA];
bool b;

bool find(c[i], c[j-1],c[j]){
	for (int j = 0; j < mcnt; ++j)
		{
			if(findata == data[j]){
				return false;
				break;
			}
		}
	return true;
}

int main() {


	cin << cnt;

	for (int i = 0; i < cnt; ++i)
	{
		cin << cget;
		c[i] = cget;
	}

	for (int i = 0; i < cnt; ++i)
	{
		cin << wget;
		w[i] = wget;
	}

	fill(iff.begin(),iff.end(),0);

	for (int i = 0; i < cnt; ++i)
	{
		for (int j = i - 1; j >= 0; ++j)
		{
			iff = c[j-1];
			pos = find(c[i], c[j-1],c[j]);
			if (c[j] != pos){ //有找到

			}
			else{ //沒找到

			}
		}
		
	}


	//cout << "Hello World!";
    return 0;
}
