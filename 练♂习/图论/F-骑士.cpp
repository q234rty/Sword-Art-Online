#include<bits/stdc++.h>
#define ll long long
#define N 1000005
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
int n,U,V,E,a[N],cnt,head[N];
struct edge{int next,to;}e[N<<1];
bool vis[N];
inline void insert(int u,int v){
	e[++cnt]=(edge){head[u],v};head[u]=cnt;
	e[++cnt]=(edge){head[v],u};head[v]=cnt;
}
inline void dfs(int x,int f){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next) if((i^1)!=f){
		if(vis[e[i].to]){
			U=x;V=e[i].to;E=i;
			continue;
		}
		dfs(e[i].to,i);
	}
}
ll ans,g[N],f[N];
inline void tree_dp(int x,int F,int cc){
	f[x]=a[x];
	g[x]=0;
	for(int i=head[x];i;i=e[i].next)
		if((i^1)!=F&&(i!=cc)&&(i^1)!=cc){
			tree_dp(e[i].to,i,cc);
			f[x]+=g[e[i].to];
			g[x]+=max(g[e[i].to],f[e[i].to]);
		}
}
int main(){
	n=read();cnt=1;
	For(i,1,n){
		a[i]=read();int x=read();
		insert(x,i);
	}
	For(i,1,n) if(!vis[i]){
		dfs(i,0);ll temp;
		tree_dp(U,0,E);temp=g[U];
		tree_dp(V,0,E);temp=max(temp,g[V]);
		ans+=temp;
	}
	printf("%lld\n",ans);
	return 0;
}