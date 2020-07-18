//Created by skyhong2002

#include <bits/stdc++.h>
using namespace std;

int N;
int a[500005] = {-1}; //i的小天使
int b[500005] = {-1}; //i的小主人
bool hasfriend[500005];
int split = 0;

void circle(int p, int head){
    //cout << "c(" << p << ", " << head << ")\n";
    hasfriend[p] = false;
    //for(int i=1; i<=N; i++) cout << hasfriend[i] << " ";
    //cout << "\n";
    if(!hasfriend[a[p]]){
        //cout << "++\n";
        split++;
        return;
    }
    circle(a[p],head);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    bool pass = false;
    
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        hasfriend[i] = true;
        if(a[i]==i) pass =true;
        if(pass) break;
    }
    
    for(int i = 1; i <= N; i++){
        if(b[i]==-1) pass = true;
        b[a[i]] = i;
        if(pass) break;
    }
    for(int i = 1; i <= N; i++){
        if(a[i]==-1) pass = true;
        if(b[i]==-1) pass = true;
        if(pass) break;
    }
    for(int i = 1; i <= N; i++){
        if(hasfriend[i]) circle(i, i);
    }

    if(pass) cout << "-1\n";
    else{
        cout << split << "\n";
    }
    return 0;

}
