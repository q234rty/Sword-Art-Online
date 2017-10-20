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
int n,m,Q,head[N],cnt;
struct edge{int next,to;}e[N<<1];
inline void insert(int u,int v){
	e[++cnt]=(edge){head[u],v};head[u]=cnt;
	e[++cnt]=(edge){head[v],u};head[v]=cnt;
}
int dfn[N],low[N],h[N],ind,q[N],top,bl[N];
bool inq[N];
inline void tarjan(int x){
	dfn[x]=low[x]=++ind;
	q[++top]=x;inq[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(!inq[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
}
int main(){
	n=read();m=read();Q=read();
	For(i,1,m){int x=read(),y=read();insert(x,y);}
	For(i,1,n) if(!dfn[i]) tarjan(i);
	return 0;
}