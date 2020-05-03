
//translater: g++-7 -std=gnu++14 -o deafult.out
//Created by http://mikucode.blogspot.com/2014/03/toj44.html

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
#define N 101
using namespace std;
struct MP{
	int x,y,c;
};
char MAP[N][N];
bool wed[N][N];
int X[4]={-1,0,1,0},Y[4]={0,1,0,-1};
int main(int argc,char *argv[])
{
	int n;
	scanf("%d",&n);
	while(n!=0){
			queue<MP> qq;
			for(int i=0;i<n;i++)scanf("%s",MAP[i]);
			fill((bool*)wed,(bool*)wed+N*N,true);
			for(int i=0;i<n;i++)
					for(int j=0;j<strlen(MAP[i]);j++)
							if(MAP[i][j]=='K'){
									qq.push((MP){i,j,0});
									wed[i][j]=false;
									goto start;
							}
			start:;
			int ans=-1;
			while(!qq.empty()){
					int x=qq.front().x,y=qq.front().y,c=qq.front().c;
					//printf("DD:x:%d,Y:%d,C:%d\n",x,y,c);
					qq.pop();
					for(int i=0;i<4;i++){
							if(wed[x+X[i]][y+Y[i]]){
								//printf("   AA:%d\n",i);
									wed[x+X[i]][y+Y[i]]=false;
									if(MAP[x+X[i]][y+Y[i]]=='#')continue;
									if(MAP[x+X[i]][y+Y[i]]=='@'){
											ans=c+1;
											goto end;
									}
									if(MAP[x+X[i]][y+Y[i]]=='.')qq.push((MP){x+X[i],y+Y[i],c+1});
							}
					}
			}
			end:;
			if(ans!=-1)printf("%d\n",ans);
			else puts("= =\"");
			scanf("%d",&n);
	}
	return 0;
}