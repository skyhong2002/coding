#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, F;
    cin >> N >> F;

    int Ci[100005];
    for(int i = 0; i < N; i++){
        cin >> Ci[i];
        Ci[i] *= 1000;
    }
    int fs;
    for(int i = 0; i < F; i++)fs += Ci[i];

    int max = fs;
    for(int i = F; i < N; i++){
        fs = fs - Ci[i-F] + Ci[i];
        if(fs < max) max = fs;
    }

    cout << fs/F << "\n";
    
}
