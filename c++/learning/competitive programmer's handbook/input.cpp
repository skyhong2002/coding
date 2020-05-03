
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

//input and ouput

#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	// cin 和 cout 最簡單的語法：

	int a, b;
	string s;
	cin >> a, b, s;

	cout << a << " " << b << " " << s << "\n";

	//如果要拿一整行，就使用getline(cin, s)

	string c;
	getline(cin, c);

	//拿到沒有東西可以用：

	string x;
	while(cin >> x){
		//code
	}

    return 0;
}