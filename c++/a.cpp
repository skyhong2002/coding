//translater: g++ -std=gnu++14 -o deafult.out
//Created by skyhong2002

//#pragma GCC optimise("O3", "unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define pb(a) push_back(a)
#define F first
#define S second
#define mp make_pair

using namespace std;

int cmp(int a, int b){
    return !(a % 5 < b % 5);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int arr[100] = {3, 1, 4, 1, 5, 9, 2, 6};
    sort(arr, arr + 8, cmp);
    for(int i = 0; i < 8; i++){
        cout << arr[i] << "\n";
    }
    return 0;

}
