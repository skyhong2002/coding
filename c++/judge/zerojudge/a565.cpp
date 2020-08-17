#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cnt=0, ans=0;
    string s;
    cin >> cnt;
    while(cin >> s){
        cnt=0;
        ans=0;
        for(char c : s){
            if(c=='p') cnt++;
            else if(c=='q'&&cnt>0){
                cnt--;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
