#include<bits/stdc++.h>
#define ll long long
#define N 255
#define oo 1e9
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int T,cnt,n,m,k,a[N][N],mx,head[N*2];
struct edge{int next,to,w;}e[200005];
inline void insert(int u,int v,int w){
	e[++cnt]=(edge){head[u],v,w};head[u]=cnt;
	e[++cnt]=(edge){head[v],u,0};head[v]=cnt;
}
queue <int> Q;
int dis[N*2];
inline bool bfs(){
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
	if(dis[T]==-1) return 0;
	return 1;
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
	while(bfs()) ans+=dfs(0,oo);
	return ans;
}
inline bool check(int mid){
	cnt=1;memset(head,0,sizeof head);
	For(i,1,n) insert(0,i,1);
	For(i,1,m) insert(n+i,T,1);
	For(i,1,n) For(j,1,m) if(a[i][j]<=mid) insert(i,j+n,1);
	if(dinic()>=k) return 1;
	else return 0;
}
int main(){
	n=read();m=read();k=n-read()+1;T=n+m+1;
	For(i,1,n) For(j,1,m) a[i][j]=read(),mx=max(mx,a[i][j]);
	int l=0,r=mx,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}