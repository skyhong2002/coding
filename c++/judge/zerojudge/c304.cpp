#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char, vector<char>> stk;
    int cnt;
    cin >> cnt;
    bool check = true
    for(int i = 0; i < cnt; i++){
        string in;
        cin >> in;
        for(auto x : in){
            if(x=='('||x=='['){
                stk.emplace(x);
            }
            else if(x==')'){
                if(stk.top()=='('){
                    stk.pop();
                }
                else{
                    check = false;
                    break;
                }
            }
            else if(x==']'){
                if(stk.top()=='('){
                    stk.pop();
                }
                else{
                    check = false;
                    break;
                }
            }
        }
        if(!stk.empty()) check = false;
        cout << (check?"Yes":"No")<<"\n"
    }
}
