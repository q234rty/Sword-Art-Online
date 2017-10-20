#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n.head[N],cnt;
struct edge{int next,to;}e[N<<1];
inline void insert(int u,int v){
	e[++cnt]=(edge){head[u],v};head[u]=cnt;
	e[++cnt]=(edge){head[v],u};head[v]=cnt;
}
int dep[N],fa[N];
inline void dfs(int x,int f){
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=f){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,x);
		}
}
int tot,p[N];
inline void Dfs(int x,int f){
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=f){
			Dfs(e[i].to,f);
			
		}
}
int main(){
	n=read();
	For(i,1,n-1){int x=read(),y=read();insert(x,y);}
	dfs(1,0);int rt=0;
	For(i,1,n) if(dep[i]>dep[rt]) rt=i;
	memset(dep,0,sizeof dep);memset(fa,0,sizeof fa);
	dfs(rt,0);int mx=0;
	For(i,1,n) if(dep[i]>dep[mx]) mx=i;
	p[++tot]=mx;
	while(mx!=rt) mx=fa[mx],p[++tot]=mx;
	tot/=2;rt=p[tot];
	Dfs(rt,0);
	return 0;
}