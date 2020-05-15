#include<iostream>
using namespace std;

bool test(int N, int K, int P[], int D){
    int n=0;
    for(int j=0; j<K; i++){
        int ns=n;
        while(D<P[n]-P[ns]){
            n++;
            if(n>=N) return false;
        }
    }
    return true;
}

int main(){
    int N, K, D;
    int P[500002];
    while(cin >> N >> K){
        for(int i=0; i<N; i++) cin >> P[i];
        sort(P; P+N);

        int dl=0, dr=N;
        while(dl==dr-1){
            if(test(N, K, P, (dl+dr)/2)) dl = (dl+dr)/2;
            else dr = (dl+dr)/2;
        }
        cout << dl << "\n";
    }
}
