#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m,cnt,head[N],dfn[N],low[N],q[N],top,Head[N];
struct edge{int next,to;}e[N*5],E[N*5];
inline void insert(int u,int v){e[++cnt]=(edge){head[u],v};head[u]=cnt;}
int bl[N],scc,ind,g[N];
bool inq[N];
inline void tarjan(int x){
	dfn[x]=low[x]=++ind;
	q[++top]=x;inq[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(inq[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]){
		scc++;int now=0;
		while(now!=x) now=q[top--],inq[now]=0,bl[now]=scc,g[scc]++;
	}
}
inline void Insert(int u,int v){
	E[++cnt]=(edge){Head[u],v};Head[u]=cnt;
}
inline void rebuild(){
	cnt=0;
	For(x,1,n){
		for(int i=head[x];i;i=e[i].next)
			if(bl[x]!=bl[e[i].to]) Insert(bl[x],bl[e[i].to]);
	}
}
int main(){	
	n=read();m=read();
	For(i,1,m){int x=read(),y=read();insert(x,y);}
	For(i,1,n) if(!dfn[i]) tarjan(i);
	rebuild();
	int ans=0;
	For(i,1,scc){
		if(!Head[i]){
			if(ans){puts("0");return 0;}
			else ans=g[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}