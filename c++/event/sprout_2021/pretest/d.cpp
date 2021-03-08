#include<bits/stdc++.h>
using namespace std;
const long long M = 100000007;

int main(){
    long long A[505][505], B[505][505], C[505][505];
    int Ar, Ac, Br, Bc, Cr, Cc;

    long long temp;

    cin >> Ar >> Ac;
    for(int i = 0; i < Ar; i++){
        for(int j = 0; j < Ac; j++){
            cin >> temp;
            A[i][j] = (temp%M+M)%M;
        }
    }
    cin >> Br >> Bc;
    for(int i = 0; i < Br; i++){
        for(int j = 0; j < Bc; j++){
            cin >> temp;
            B[i][j] = (temp%M+M)%M;
        }
    }
    int situ;
    if(Ac == Br){
        situ = 0;
        Cr = Ar;
        Cc = Bc;
    }
    else if(Bc == Ar) situ = 1;
    else situ = 2;

    if(situ == 1) cout << "incommutable!\n";
    else if(situ == 2) cout << "unmultipliable!\n";
    else if(situ == 0){
        for(int i = 0; i < Cr; i++){
            for(int j = 0; j < Cc; j++){
                temp = 0;
                for(int k = 0; k < Ac; k++){
                    temp += A[i][k]*B[k][j];
                    temp = (temp%M+M)%M;
                }
                C[i][j] = temp;
                cout << C[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
