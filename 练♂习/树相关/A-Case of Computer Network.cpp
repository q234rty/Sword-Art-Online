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
int n,m,Q,head[N],cnt=1,x[N],y[N],T,f[N],g[N];
bool vis[N<<1],inq[N];
struct edge{int next,to;}e[N<<1];
inline void insert(int u,int v){
	e[++cnt]=(edge){head[u],v};head[u]=cnt;
	e[++cnt]=(edge){head[v],u};head[v]=cnt;
}
int scc,dfn[N],low[N],ind,q[N],top,ble[N],bl[N];
inline void tarjan(int x){
	dfn[x]=low[x]=++ind;
	q[++top]=x;inq[x]=1;ble[x]=T;
	for(int i=head[x];i;i=e[i].next)
		if(vis[i]) continue;
		else if(!dfn[e[i].to]) vis[i]=vis[i^1]=1,tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(inq[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]){
		scc++;int now=0;
		while(now!=x) now=q[top--],bl[now]=scc,inq[now]=0;
	}
}
int dep[N],fa[N][20],bin[20];
inline void dfs(int x){
	vis[x]=1;
	For(i,1,19){
		if(bin[i]>dep[x]) break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y];
	For(i,0,19) if(bin[i]&del) x=fa[x][i];
	Rep(i,19,0) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	if(x==y) return x;
	return fa[x][0];
}
inline void Dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(!vis[e[i].to]){
			Dfs(e[i].to);
			f[x]+=f[e[i].to];
			g[x]+=g[e[i].to];
		}
}
int main(){
	bin[0]=1;For(i,1,19) bin[i]=bin[i-1]<<1;
	n=read();m=read();Q=read();
	For(i,1,m){x[i]=read();y[i]=read();insert(x[i],y[i]);}
	For(i,1,n) if(!dfn[i]) ++T,tarjan(i);
	memset(head,0,sizeof head);memset(vis,0,sizeof vis);cnt=0;
	For(i,1,m) if(bl[x[i]]!=bl[y[i]]) insert(bl[x[i]],bl[y[i]]);
	For(i,1,scc) if(!vis[i]) dfs(i);
	while(Q--){
		int u=read(),v=read();
		if(ble[u]!=ble[v]){puts("No");return 0;}
		u=bl[u];v=bl[v];int Lca=lca(u,v);
		f[u]++;f[Lca]--;g[v]++;g[Lca]--;
	}
	memset(vis,0,sizeof vis);
	For(i,1,scc) if(!vis[i]) Dfs(i);
	For(i,1,scc) if(f[i]&&g[i]){puts("No");return 0;}
	puts("Yes");
	return 0;
}