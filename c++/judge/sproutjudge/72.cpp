
//AC

//https://neoj.sprout.tw/problem/72

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int cnt, fcnt;
double trif, tris, trit, tril;
double first, second, third, last;
double func[15][5];

double calculate(double a){
	double num = 0;
	for(int s = 0; s < fcnt; s++) 
	{
		num = max(num, func[s][0]*pow(a - func[s][1], 2) + func[s][2]);
	}
	return num;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	double MAXA = 99999, MAXN = 91092083;
	
	cout << fixed << setprecision(5);

	cin >> cnt;
	for(int i = 0; i < cnt; i++)
	{
		cin >> fcnt;
		for(int j = 0; j < fcnt; j++)
		{
			cin >> func[j][0] >> func[j][1] >> func[j][2];
		}

		trif = 0;
		tril = 300.1;
		
		first = calculate(trif);
		last = calculate(tril);

		tris = (trif * 2 + tril) / 3;
		trit = (trif + tril * 2) / 3;

		second = calculate(tris);
		third = calculate(trit);

		while(abs(first - last) > 0.00000001 || abs(second - third) > 0.00000001) //小數點後至少再兩位
		{
			tris = (trif * 2 + tril) / 3;
			trit = (trif + tril * 2) / 3;

			//cout << trif << " " << tris << " " << trit << " " << tril << "\n";

			second = calculate(tris);
			third = calculate(trit);

			//cout << calculate(trif) << " " << calculate(tris) << " " << calculate(trit) << " " << calculate(tril) << "\n\n";

			if (second < third) { // 最小值不在最右邊
				tril = trit;
			}
			else if (second > third){ // 最小值不在最左邊
				trif = tris;
			}
			else{ //最小值在中間
				tril = trit;
				trif = tris;
			}

			first = calculate(trif);
			last = calculate(tril);
			
		}
		cout << (last + first) / 2 << "\n";
		//if(i < cnt - 1) cout << "\n";
	}
    return 0;
}