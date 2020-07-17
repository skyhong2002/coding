#include<bits/stdc++.h>
using namespace std;

int main(){

    int a, b, c;
    int i, j, k;
    while(cin >> i >> j >> k){
        a = min(min(i, j), k);
        c = max(max(i, j), k);
        b = i + j + k - a - c;
        cout << a << " " << b << " " << c << " \n";
        if(a*a+b*b==c*c) cout << "Right\n";
        else if(a*a+b*b>c*c) cout << "Acute\n";
        else if(a+b<=c) cout << "No\n";
        else cout << "Obtuse\n";
    }
    return 0;
}
