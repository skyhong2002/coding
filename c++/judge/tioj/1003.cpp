#include<bits/stdc++.h>
using namespace std;

int cut(int a){
    if(a==0) return 1;
    else return (cut(a-1)+a-1);
}

int main(){

    int a;
    while(cin >> a){
        cout << cut(a+1) << "\n";
    }

    return 0;
}
