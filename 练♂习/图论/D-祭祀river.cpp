#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define inf 1e9
#define eps 1e-10
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m,f[105][105],T,head[205],cnt;
struct edge{int next,to,w;}e[N];
inline void insert(int u,int v,int w){
	e[++cnt]=(edge){head[u],v,w};head[u]=cnt;
	e[++cnt]=(edge){head[v],u,0};head[v]=cnt;
}
int dis[205];
inline bool bfs(){
	queue <int> Q;
	Q.push(0);
	memset(dis,-1,sizeof dis);dis[0]=0;
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		for(int i=head[x];i;i=e[i].next)
			if(e[i].w&&dis[e[i].to]==-1){
				dis[e[i].to]=dis[x]+1;
				Q.push(e[i].to);
			}
	}
	if(dis[T]!=-1) return 1;
	return 0;
}
inline int dfs(int x,int w){
	if(x==T) return w;
	int used=0;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].w&&dis[e[i].to]==dis[x]+1){
			int py=dfs(e[i].to,min(e[i].w,w-used));
			e[i].w-=py;e[i^1].w+=py;used+=py;
			if(used==w) return used;
		}
	if(!used) dis[x]=-1;
	return used;
}
inline int dinic(){
	int ans=0;
	while(bfs()) ans+=dfs(0,inf);
	return ans;
}
int main(){
	n=read();m=read();
	For(i,1,m){
		int x=read(),y=read();
		f[x][y]=1;
	}
	For(k,1,n) For(i,1,n) For(j,1,n) f[i][j]|=(f[i][k]&f[k][j]);
	T=2*n+1;cnt=1;
	For(i,1,n) insert(0,i,1);
	For(i,1,n) insert(i+n,T,1);
	For(i,1,n) For(j,1,n) if(f[i][j]) insert(i,j+n,inf);
	printf("%d\n",n-dinic());
	return 0;
}