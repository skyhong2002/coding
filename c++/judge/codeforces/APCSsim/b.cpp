#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    int a, b, c, d;
    string A, B;
    int ac=0, bc=0;

    cin >> n >> k >> a >> b >> c >> d >> A >> B;

    int ad=0, bd=0;
    
    string win = "";

    for(int i=0; i<A.length(); i++){
        if( (A[i]==*"R" && B[i]==*"P") ||
            (A[i]==*"P" && B[i]==*"S") ||
            (A[i]==*"S" && B[i]==*"R") ) win = "B";
        else if(A[i]==B[i]) win = "D";
        else win = "A";

        if(win=="A"){
            ad=0;
            bd++;
        }
        else if(win=="B"){
            ad++;
            bd=0;
        }
        else{
            ad=0; bd=0;
        }

        if(win=="A"){
            ac+=a;
            if(bd>=k)bc+=d;
            else bc+=c;
        }
        else if(win=="B"){
            if(ad>=k)ac+=d;
            else ac+=c;
            bc+=a;
        }
        else{
            ac+=b;
            bc+=b;
        }
    }
    cout << ac << " " << bc << "\n";

}
