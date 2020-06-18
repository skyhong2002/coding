#include<bits/stdc++.h>
using namespace std;

int main(){
    string string; 
    while(getline(cin,string)){
        for(int i=0; i<string.size(); i++){
            char c=string[i]-7;
            cout << c ;
        }
        cout << "\n";
    }
    return 0;
}
