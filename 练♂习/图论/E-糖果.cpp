#include<bits/stdc++.h>
#define ll long long
#define N 100005
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
int n,m,head[N],cnt,in[N];
struct edge{int next,to,w;}e[N<<2];
inline void insert(int u,int v,int w){e[++cnt]=(edge){head[u],v,w};head[u]=cnt;}
int dis[N];
bool inq[N];
inline bool spfa(){
	queue <int> Q;Q.push(0);
	memset(dis,-1,sizeof dis);dis[0]=0;
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		for(int i=head[x];i;i=e[i].next)
			if(dis[e[i].to]<dis[x]+e[i].w){
				if(++in[e[i].to]>=n) return 0;
				dis[e[i].to]=dis[x]+e[i].w;
				if(!inq[e[i].to]) inq[e[i].to]=1,Q.push(e[i].to);
			}inq[x]=0;
	}
	return 1;
}
int main(){
	n=read();m=read();
	For(i,1,m){
		int opt=read(),x=read(),y=read();
		if(opt==1){insert(x,y,0);insert(y,x,0);}
		if(opt==2){if(x==y){puts("-1");return 0;}insert(x,y,1);}
		if(opt==3){insert(y,x,0);}
		if(opt==4){if(x==y){puts("-1");return 0;}insert(y,x,1);}
		if(opt==5){insert(x,y,0);}
	}
	Rep(i,n,1) insert(0,i,1);
	if(!spfa()){puts("-1");return 0;}
	ll ans=0;
	For(i,1,n) ans+=dis[i];
	printf("%lld\n",ans);
	return 0;
}