#include<bits/stdc++.h>
using namespace std;

int A[500005], B[500005];
int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < 500005; i++){
        A[i] = 0;
        B[i] = 0;
    }
    int I, O;
    for(int i = 0; i < N; i++){
        cin >> I;
        B[I]++;
    }
    for(int i = 0; i < M; i++){
        cin >> I >> O;
        if(I == 0){
            if(A[O] > 0) A[O]--;
            else if(B[O] > 0){
                B[O]--;
                N--;
            }
            else A[O]--;
        }
        else if(I == 1){
            A[O]++;
        }
    }
    cout << N << "\n";
    for(int i = 0; i < 500005; i++){
        if(B[i] == 0) continue;
        for(int j = 0 ; j < B[i]; j++){
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}
