
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int c;
	cin >> c;

	int step, num;
	stack<int> s;

	for(int i = 0; i < c; i++){
		
		cin >> step;

		if(step == 1){
			if(!s.empty()) s.pop();
		}
		else if(step == 2){
			cout << s.top() << "\n";
		}
		else if(step == 3){
			cin >> num;
			s.push(num);
		}
		
	}

    return 0;
}