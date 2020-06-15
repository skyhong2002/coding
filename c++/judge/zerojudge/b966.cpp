#include<bits/stdc++.h>
using namespace std;

int main(){
    int l, r, N;
    map<int, int> T{0};

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> l >> r;
        if(l==r)continue;


        T[l]=1;
        T[r]=-1;
        

    }

    return 0;
}
