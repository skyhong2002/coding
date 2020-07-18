#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
	int cnt;
	long num;
	deque<long> deq;

	cin >> cnt;
	cin >> num;
	deq.push_back(num);

	for(int i=1; i<cnt; i=i+1){
		cin >> num;
		if(!deq.empty()){
			if(deq.back() == num) deq.pop_back();
			else deq.push_back(num);
		}	
		else{
			deq.push_back(num);
		}
	}

	if(deq.empty()) cout << "Meow" << endl;

	while(!deq.empty()){
		cout << deq.front() << " ";
		deq.pop_front();
	}
	cout << "\n";

    return 0;
}