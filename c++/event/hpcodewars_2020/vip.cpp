#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i==0){
            //cout << n << " % " << i << " = 0\n";
            return false;
        }
    }
    return true;
}
    

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    char A, B, C, D;

    cin >> A >> B >> C >> D;

    int a[4];
    a[0] = A - '0';
    a[1] = B - '0';
    a[2] = C - '0';
    a[3] = D - '0';

    int N = 0;
    N += a[0];
    N *= 10;
    N += a[1];
    N *= 10;
    N += a[2];
    N *= 10;
    N += a[3];
    
    int TENET = 0;

    TENET += a[3];
    TENET *= 10;
    TENET += a[2];
    TENET *= 10;
    TENET += a[1];
    TENET *= 10;
    TENET += a[0];

    if(isprime(N) && isprime(TENET)) cout << "IS VIP";
    else cout << "NOT VIP";

    return 0;
}
