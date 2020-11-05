#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
    /*cout << int('A') << " " << int('Z') << "\n";
    cout << int('a') << " " << int('z') << "\n";
    cout << int(' ');*/
    cin >> s;
    int N = s.size();
    int ans = 0;
    //cout << N << "\n";
    for(int i = 0; i < N; i++){
        if(int(s[i])>=65 && int(s[i])<=90){//A
            ans += 2;
        }
        else if(int(s[i])>= 97 && int(s[i])<= 122){//a
            ans += 1;
        }
        else{//_
            ans += 1;
        }
    }
    cout << ans << "\n";
}
