#include<iostream>
using namespace std;
#include<algorithm>
#include<string.h>
#include<set>

const string ans[13] = {"1m", "9m", "1p", "9m", "1s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z"};

bool check(set<string> st){
	for (int i = 0; i < 13; i++){
		if (!st.count(ans[i])){
			cout << ans[i]  << i << endl;
			return false;
		}
	}
	return true;
}

int main(){
	int T;
	cin  >> T;
	
	for (int i = 0; i < T; i++){
		string arr[14];
		set<string> st;
		for (int j = 0; j < 14; j++){
			cin >> arr[j];
			st.insert(arr[j]);
		}
		sort(arr, arr + 14);
		/*
		char s[100] = "";
		for (int j = 0; j < 14; j++){
			printf("%c%c",arr[j].first + '0', arr[j].second);
			s[j * 2] = arr[j].first + '0';
			s[j * 2 + 1] = arr[j].second;
		}
		s[28] = '\0';*/
		bool b1 = true;
		for (int i = 0; i < 7; i++){
			if (arr[i * 2] != arr[i * 2 + 1] || (i != 0 && arr[i * 2] == arr[i * 2 - 1])){
				b1 = false;
				break;
			}
		}
		if (b1){
			printf("chiitoitsu(Seven pairs)\n");
		}
		else{
			if (check(st)){
				printf("kokushi musou(Thirteen orphans)\n");
			}
			else{
				printf("none\n");
			}
		}
	}
}
