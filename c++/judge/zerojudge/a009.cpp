
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int MAXA = 99999, MAXN = 91092083;
	int discriminant, a, b, c, ans[2];

	while(cin >> a >> b >> c){

		discriminant = b*b - (4 * a * c);
		//cout << discriminant << '\n';

		if (discriminant < 0)cout << "No real root\n";
		else if(discriminant > 0){
			ans[0] = (sqrt(discriminant) - b) / (2 * a);
			ans[1] = (- sqrt(discriminant) - b) / (2 * a);
			cout << "Two different roots x1=" << ans[0] << " , x2=" << ans[1] << "\n";
		}
		else{
			ans[0] = (sqrt(discriminant) - b) / (2 * a);
			cout << "Two same roots x=" << ans[0] << "\n";
		}
		
	}
	
	

    return 0;
}