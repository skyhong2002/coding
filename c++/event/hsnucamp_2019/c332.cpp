
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

#include <bits/stdc++.h>

//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	//int MAXA = 99999, MAXN = 91092083;
	int cnt;
	cin >> cnt;

	deque<int> d;
	int order, num;

	for(int i = 0; i < cnt; i++){
		cin >> order;
		
		switch(order){
			case 1:
				if(d.empty()) break;
				cout << d.back() << "\n";
				d.pop_back();
				break;
			case 2:
				if(d.empty()) break;
				cout << d.front() << "\n";
				d.pop_front();
				break;
			case 3:
				cin >> num;
				d.push_back(num);
				break;
			case 4:
				cin >> num;
				d.push_front(num);
				break;


		}

	}

    return 0;
}