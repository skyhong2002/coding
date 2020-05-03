#pragma GCC optimise("O3", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int act, ufocnt;
	cin >> act >> ufocnt;
	int ufo[ufocnt];
	int battery[ufocnt];
	
	for(int i=0; i<ufocnt; i++){
		ufo[i] = 1;
	}
	
	for(int i=0; i<ufocnt; i++){
		battery[i] = 100;
	}
		
	
	int actnum;
	int ufonum;
	int batterytake;
	
	for(int a=0; a<act; a++){
		
		cin >> actnum >> ufonum;
		if(actnum == 1){
			
			if(ufo[ufonum] == 0){
				cout << "Access Denied for UFO "<< ufonum <<": UNAVAILABLE.\n";
			}
			else{
				if(battery[ufonum] < 30){
					cout << "Access Denied for UFO "<< ufonum <<": LOW BATTERY.\n";
				}
				else{
					cout << "Access Granted for UFO "<< ufonum <<".\n";
					ufo[ufonum] = 0;
				}
			}
		}
		else if(actnum == 2){
			cin >> batterytake;
			if(ufo[ufonum] == 1){
				cout << "Return Failure for UFO "<< ufonum <<": NOT IN RENT.\n";
			}
			else{
				battery[ufonum] -= batterytake;
				if(battery[ufonum] < 0){
					battery[ufonum] = 0;
				}
				cout << "Return Success for UFO "<< ufonum <<": Remaining Battery "<< battery[ufonum] <<" percent(s).\n";
				ufo[ufonum] = 1;
			}
			
		}
		else if(actnum == 3){
			cout << "Battery Renewal for UFO "<< ufonum <<".\n";
			battery[ufonum] = 100;
		}
		
	}
	
	
}


