
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by Skychopath

//https://neoj.sprout.tw/problem/89/

// sort a vector pair https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/

#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt;
	int cook, eat;
	int ans, now;
	vector< pair<int,int> > people;

	cin >> cnt;
	while(cnt != 0)
	{
		people.clear();
		for(int i = 0; i < cnt; i++)
		{
			cin >> cook >> eat;
			people.push_back(make_pair(eat, cook));
		}

		sort(people.begin(), people.end());

		now = people.back().first + people.back().second;
		ans = now;

		while(!people.empty())
		{
			now = now - people.back().first;
			people.pop_back();
			now = now + people.back().first + people.back().second;
			ans = max(ans, now);
			cout << now << " " << ans << " " << people.back().first << " " << people.back().second << "\n";
			
		}
		cout << ans << "\n";
		
		cin >> cnt;
	}

    return 0;
}