#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int g[n]; 
    for(int i=0; i<n; i++) cin >> g[i];
    
    sort(g, g+sizeof(g)/sizeof(g[0]));
   
    //for(int i=0; i<n; i++) cout << g[i] << " ";
    //cout << "\n";
    
    int t = g[0];
    int tc = 0;
    int lost[3]={0};
    for(int i=0; i<n; i++){
        if(t==g[i]){
            tc++;
            if(tc==3)tc-=3;
        }
        else{
            if(tc==1) lost[1]++;
            else if(tc==2) lost[2]++;
            tc=1;
            if(i!=n-1)t=g[i];
        }
    }


    int ans=0;
    if(lost[1]>lost[2]){
        ans+=lost[2];
        lost[1]-=lost[2];
        lost[2]=0;
        
        lost[1]-=2;
        ans+=1;
        
        ans+=(lost[1]/3)*2;
    }
    else if(lost[1]<lost[2]){
        ans+=lost[1];
        lost[2]-=lost[1];
        lost[1]=0;
        
        lost[2]-=1;

        ans+=(lost[2]/3)*2;
    }
    cout << ans;    
}
