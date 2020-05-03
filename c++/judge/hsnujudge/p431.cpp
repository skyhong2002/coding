//translater: g++ -std=gnu++14 -o deafult.out
//Created by skyhong2002

//#pragma GCC optimise("O3", "unroll-loops")
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long
#define pb(a) push_back(a)
#define F first
#define S second
#define mp make_pair

using namespace std;

int main(){    

    ll a, b;
    cin >> a >> b;
    if(a > b) swap(a,b);

    const int si = sqrt(2147483647);

    bool prime[400000]={0};
    prime[0]=prime[1]=1;
    for(int i=2;i*i<=si;i++)
        if(!prime[i])
            for(int j=i*i;j<=si;j+=i)
                prime[j]=1;


    //不鏽鋼鴕鳥篩法
    bool prime_table[400000]={0};
    for(int i = 2; i*i <= b; i++){
        if(prime[i]) continue;
        cout <<  i << "\n";
        for(int j = (((a-1)/i)+1)*i; j <= b; j += i){
            if(j==i) continue;
            if(j-a>0) prime_table[j-a]=1;
        }
    }

    ll ans = 0;
    for(int i = 0; i <= b-a; i++)
        if(!prime_table[i])
            ans++;

    cout << ans << "\n";

    return 0;

}
