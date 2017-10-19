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
int n,m,cnt,head[N];
struct data{int x,y;double val;}a[N];
struct edge{int next,to;double w;}e[N];
inline void insert(int u,int v,double w){e[++cnt]=(edge){head[u],v,w};head[u]=cnt;}
double dis[N];
bool vis[N],flag;
inline void spfa(int x){
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
		if(dis[e[i].to]>dis[x]+e[i].w){
			if(vis[e[i].to]){flag=1;break;}
			dis[e[i].to]=dis[x]+e[i].w;
			spfa(e[i].to);
		}
	vis[x]=0;
}
inline bool check(double mid){
	cnt=0;memset(head,0,sizeof head);
	For(i,1,m) insert(a[i].x,a[i].y,a[i].val-mid);
	memset(vis,0,sizeof vis);
	memset(dis,0,sizeof dis);
	flag=0;
	For(i,1,n){
		spfa(i);if(flag) return 1;
	}
	return 0;
}
int main(){
	n=read();m=read();
	For(i,1,m) a[i]=(data){read(),read()},scanf("%lf",&a[i].val);
	double l=-10000000,r=10000000,ans;
	while(r-l>eps){
		double mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid;
		else l=mid;
	}
	printf("%.8lf",ans);
	return 0;
}