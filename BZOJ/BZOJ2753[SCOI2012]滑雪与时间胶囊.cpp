#include<bits/stdc++.h>
#define ll long long
#define N 1000005
#define int ll
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m,h[N],head[N],cnt,f[N],tot;
inline int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
struct edge{int next,to,w;}e[N<<1];
struct Edge{
	int x,y;ll val;
}E[N<<1];
inline bool operator <(Edge a,Edge b){
	return (h[a.y]==h[b.y])?a.val<b.val:h[a.y]>h[b.y];
}
int sum;
inline void insert(int u,int v,int w){
	if(h[u]>=h[v]) e[++cnt]=(edge){head[u],v,w},head[u]=cnt;
	if(h[v]>=h[u]) e[++cnt]=(edge){head[v],u,w},head[v]=cnt;
}
bool vis[N];
inline void dfs(int x,int fa){
	vis[x]=1;sum++;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa){
			E[++tot]=(Edge){x,e[i].to,e[i].w};
			if(!vis[e[i].to]) dfs(e[i].to,x);
		}
}
ll ans;
main(){
	n=read();m=read();
	For(i,1,n) h[i]=read();
	For(i,1,m){
		int u=read(),v=read(),w=read();
		insert(u,v,w);
	}
	dfs(1,0);
	For(i,1,n) f[i]=i;
	sort(E+1,E+1+tot);
	For(i,1,tot){
		int u=find(E[i].x),v=find(E[i].y);
		if(u!=v) f[u]=v,ans+=1ll*E[i].val;
	}
	printf("%lld %lld\n",sum,ans);
	return 0;
}