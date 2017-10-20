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
int n,in[N],cnt,head[N];
struct edge{int next,to;}e[N<<1];
inline void insert(int u,int v){
	e[++cnt]=(edge){head[u],v};head[u]=cnt;in[u]++;
	e[++cnt]=(edge){head[v],u};head[v]=cnt;in[v]++;
}
bool lef[N];
int Cnt[N];
inline void dfs(int x,int fa){
	lef[x]=1;
	for(int i=head[x];i;i=e[i].next) if(e[i].to!=fa&&in[e[i].to]<=2) dfs(e[i].to,x);
}
int main(){
	n=read();
	For(i,1,n-1){int u=read(),v=read();insert(u,v);}
	For(i,1,n) if(in[i]==1) dfs(i,0);
	For(x,1,n) for(int i=head[x];i;i=e[i].next) if(lef[e[i].to]) Cnt[x]++;
	For(x,1,n) if(!lef[x]){
		int sum=0;
		for(int i=head[x];i;i=e[i].next) if(!lef[e[i].to]&&in[e[i].to]-min(Cnt[e[i].to],2)>=2) sum++;
		if(sum>=3) return puts("No")&0;
	}
	puts("Yes");
	return 0;
}
