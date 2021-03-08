#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> m;
    int cnt;
    cin >> cnt;
    for(int i = 0; i < cnt; i++){
        string coun, a, b;
        cin >> coun >> a >> b;
        if(m.find(coun) != m.end()){
            m[coun] ++;
        }
        else{
        m[coun] = 1;
        }
    }
    for(auto itr = m.begin(); itr != m.end(); ++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}
