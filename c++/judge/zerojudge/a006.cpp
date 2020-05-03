
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int k = 7;
	string s;
	while(getline(cin, s)){
		for(int i = 0; i < s.length(); i++){
			s[i] -= k;
		}
		cout << s << "\n";
	}

    return 0;
}