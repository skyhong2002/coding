#include<bits/stdc++.h>
using namespace std;

int check(string A, string B, int p, int l){
    map<char, char> mA, mB;
    for(int i = 0; i < l; i++){
        auto iA = mA.find(A[i]);
        auto iB = mB.find(B[(i+p+l)%l]);
        if(iA == mA.end() && iB == mB.end()){
            mA[A[i]] = B[(i+p+l)%l];
            mB[B[(i+p+l)%l]] = A[i];
        }
        else if(iA->second == B[(i+p+l)%l] && iB->second == A[i]) continue;
        else return 0;
    }
    return 1;
}

int main(){
    string A, B;
    cin >> A >> B;
    int l = A.size();
    int cnt = 0;
    for(int i = 0; i < l; i++){
        if(check(A, B, i, l) == 1) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
