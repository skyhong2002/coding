#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
ll t[301], h[301];
ll merge(ll a, ll b){
    if(b == -1) b = N-1;
    //cout << "merge " << a << " " << b << ", ";
    h[a] = h[b];
    //cout << a << ": " << h[a] << " " << t[a] << ", J+=" << h[a]*t[a]*t[b] << "\n";
    return h[a]*t[b]*t[a];
}

int main(){
    while(cin >> N){
        for(ll i = 0; i < N; i++){
            cin >> h[i] >> t[i];
        }
        ll J = 0;
        for(ll i = 0; i < N-1; i++){
            J += merge(i, i-1);
        }
        cout << J << "\n";
    }
}
