#include<bits/stdc++.h>
using namespace std;

int gcd (int a,int b)
{
  int r=1;
  while (r!=0)
   {
     r = a % b;
     a = b;
     b = r;
   }
  return a;
} 

int main(){
    long long N, K;
    int A[505];
    while(cin >> N >> K){
        int ans = 0;
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        if(N==2){
            for(int i = -K; i <= K; i++){
                if(A[0]+i == 0) continue;
                if(A[1]-i == 0) continue;
                int temp = gcd(A[0]+i, A[1]-i);
                if(temp > ans) ans = temp;
            }
        }
        cout << ans << "\n";
    }
}
