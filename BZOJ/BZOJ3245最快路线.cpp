#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
#define N 155
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m,end,head[N],cnt;
struct edge{int next,to,V,L;}e[N*N*2];
inline void insert(int u,int v,int V,int L){
	e[++cnt]=(edge){head[u],v,V,L};head[u]=cnt;
}
struct data{int x,V;}from[N][505];
queue <data> Q;
int inq[N][505];
double dis[N][505];
inline void spfa(){
	Q.push((data){1,70});
	memset(dis,127,sizeof dis);
	dis[1][70]=0;
	while(!Q.empty()){
		data x=Q.front();Q.pop();
		for(int i=head[x.x];i;i=e[i].next){
			if(e[i].V==0){
				if(dis[e[i].to][x.V]>dis[x.x][x.V]+1.0*e[i].L/x.V){
					dis[e[i].to][x.V]=dis[x.x][x.V]+1.0*e[i].L/x.V;
					from[e[i].to][x.V]=(data){x.x,x.V};
					if(!inq[e[i].to][x.V]) Q.push((data){e[i].to,x.V}),inq[e[i].to][x.V]=1;
				}
			}else{
				if(dis[e[i].to][e[i].V]>dis[x.x][x.V]+1.0*e[i].L/e[i].V){
					dis[e[i].to][e[i].V]=dis[x.x][x.V]+1.0*e[i].L/e[i].V;
					from[e[i].to][e[i].V]=(data){x.x,x.V};
					if(!inq[e[i].to][e[i].V]) Q.push((data){e[i].to,e[i].V}),inq[e[i].to][e[i].V]=1;
				}
			}
		}inq[x.x][x.V]=0;
	}
}
inline void print(int x,int V){
	if(x!=1) print(from[x][V].x,from[x][V].V);
	if(x!=end) printf("%d ",x-1);
	else printf("%d",x-1);
}
int main(){
	n=read();m=read();end=read()+1;
	For(i,1,m){
		int u=read(),v=read(),V=read(),L=read();
		insert(u+1,v+1,V,L);
	}
	spfa();
	int mx=0;
	For(i,1,500) if(dis[end][i]<dis[end][mx]) mx=i;
	print(end,mx);
	return 0;
}