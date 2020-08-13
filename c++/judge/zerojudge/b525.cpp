#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD int(1e9+7)

ll fibm[32][4];

void matmul(int t){
    // a b
    // c d
    ll a = fibm[t-1][0];
    ll b = fibm[t-1][1];
    ll c = fibm[t-1][2];
    ll d = fibm[t-1][3];

    fibm[t][0]= (a*a + b*c)%MOD;
    fibm[t][1]= (a*b + b*d)%MOD;
    fibm[t][2]= (a*c + c*d)%MOD;
    fibm[t][3]= (b*c + d*d)%MOD;
}

void build(int t){
    fibm[0][0]= 1;
    fibm[0][1]= 1;
    fibm[0][2]= 1;
    fibm[0][3]= 0;
    
    for(int i = 1; i<= t; i++){
        matmul(i);
    }
}

int main(){
    
    build(30);
    ll m, f, k;
    while(cin >> m >> f >> k){
        //       f
        //       m
        // a b af+bm
        // c d cf+dm
        int bit = 0;
        ll add[4];
        while(k){
            if(k%2==1){
                for(int i=0; i<4; i++){
                    add[i] += fibm[bit][i];
                }
                k--;
            }
            k/=2;
            bit++;
        }
        ll ans = (add[0]*f+add[1]*m)%MOD;
        ans += (add[2]*f+add[3]*m)%MOD;
        ans = ans%MOD;
        cout << ans << "\n";
    }

    return 0;
}

/*
    m = f
    f = f + m

          f
          m
    1 1  f+m
    1 0   f
*/
