#include<bits/stdc++.h>
using namespace std;

int main(){

    string a;
    int cnt;
    cin >> cnt;
    
    for(int i=0; i<cnt; i++){
        stack<char> stk;
        bool b = true;
        cin >> a;
        for(char c : a){
            if (a=='(') stk.push('(');
            else if(a=='[') stk.push('[');
            else if(a==')'){
                if(stk.top()=='(')stk.pop();
                else b = false;
            }
            else{
                if(stk.top()=='[')stk.pop();
                else b = false;
            }
        }
        if(!stk.empty()) b = false;
        cout << (b ? "Yes" : "No");
    }
    return 0;
}
