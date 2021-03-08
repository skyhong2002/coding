#include<bits/stdc++.h>
using namespace std;

struct Node{
    int player_id;
    Node* _next;
    Node* _before;
    Node() { //初始化
        _next = NULL;
        _before = NULL;
    }
}

Node* player[100005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        player[i] = new Node;
        player[i]->player_id = i;
    }

}
