#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> station;
    string ip = "";

    cin >> ip;
    int ipl = ip.length();

    string s="";
    for(int i = 0; i < ipl; i++){
        s.push_back(ip[i]);
        if(ip[i+1]=='-'||i==ipl-1){
            station.push_back(s);
            i+=2;
            s="";
            continue;
        }
    }
    for(int i = station.size()-1; i >=0; i--){
        cout << station[i] << (i!=0?"<-":"\n");
    }
}
