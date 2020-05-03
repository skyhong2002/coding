//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

//20190109
//AC

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int factor;
	int cnt, switchcnt = 0;
	cin >> cnt;
	int light[cnt];

	for(int i = 0; i < cnt; i++) cin >> light[i];

	for(int i = cnt - 1; i >= 0; i--){
		if(light[i] == 0){
			factor = 1;
			while(factor*factor <= i + 1){
				//cout << (i + 1) << " " << factor << " ";
				if ((i + 1) % factor == 0){
					if (light[factor - 1] == 0) {
						light[factor - 1] = 1;
						//cout << "switch light to on \n";
					}
					else{
						light[factor - 1] = 0;
						//cout << "switch light to off\n";
					}
					
					if ((i + 1)/factor != factor) {
						if (light[(i + 1)/factor - 1] == 0) {
							light[(i + 1)/factor - 1] = 1;
							//cout << "switch light to on \n";
						}
						else{
							light[(i + 1)/factor - 1] = 0;
							//cout << "switch light to off\n";
						}
					}
				}
				factor = factor + 1;
			}
			switchcnt = switchcnt + 1;
		}
		//for(int j = 0; j < cnt; j++) cout << light[j] << " ";
		//cout << "switchcnt = " << switchcnt << "\n";
	}

	cout << switchcnt << "\n";

    return 0;
}