//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int cnt;
int num[15], q[6];

int getnum(int a, int b, int g[6]){ //(現在執行到第幾個, 已經拿了幾個數字, [六,個,數,字,的,序號])
		if(a == cnt && b < 5) return 0; //走完但是拿不滿6個 捨去
		if(b <= 5){
			
		}
	return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	cin >> cnt;

	while(true){
		cin >> cnt;
			for(int i = 0; i < cnt; i++)
			{
				
			}
			
		if(cnt == 0) break;
		cout << "\n";
	}

    return 0;
}

//TLE

//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

/*
#pragma GCC optimise("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MAXA = 99999, MAXN = 91092083;
	int cnt, separate, sum;
	int num[15], reco[15];
	cin >> cnt;

	while(1)
	{
		if (cnt == 0) break;
		for(int i = 0; i < cnt; i++) cin >> num[i];
		
		//建立所有配對

		for(int i = pow(2, cnt) - 1; i >= 0; i--)
		{
			separate = i;
			sum = 0;
			for(int j = cnt - 1; j >= 0; j--)
			{
				reco[j] = 0;
				if(separate >= pow(2, j))
				{
					separate -= pow(2, j);
					reco[j] = 1;
					sum += 1;
				}
				if(sum > 6) break;
			}

			if(sum == 6)
			{
				for(int j = cnt - 1; j >= 0; j--)
				{
					if(reco[j] == 1)
					{
						cout << num[cnt - j - 1];
						sum -= 1;
						if(sum != 0) cout << " ";
					}
				}

				cout << "\n";
			}
			
			
			
		}

		cin >> cnt;
		if(cnt == 0) break;
		cout << "\n";

	}

    return 0;
}

*/