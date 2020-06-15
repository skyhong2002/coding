#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n; cin >> n;
    
    const int N=n;
    int s = 0;
    vector<pair<int, int>> f; //Factor
    for(int i=2; i<=N; i++){
        int dump=0;
        while(!(n%i)){
            dump++;
            n=n/i;
        }
        if(!dump) continue; s++;
        f.emplace_back(i, dump);
    }
    
    int i=0;
    for (const auto g:f) {
        if(i) cout <<" * ";
        i=1;
        cout << g.first;
        if(g.second>1)cout << "^" << g.second;
    }

    return 0;
}
