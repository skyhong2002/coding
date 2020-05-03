//translater: g++ -std=gnu++14 -o deafult.out
//Created by skyhong2002

#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a,b,c,s;

    cin >> a >> b >> c;

    s = (a + b + c)/2;

    int ans = s*(s-a)*(s-b)*(s-c);

    cout << ans << "\n";

    return 0;


}
