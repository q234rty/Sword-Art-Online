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
int n,head[N],cnt;
struct edge{int next,to;}e[N<<1];
inline void insert(int u,int v){
	e[++cnt]=(edge){head[u],v};head[u]=cnt;
	e[++cnt]=(edge){head[v],u};head[v]=cnt;
}
int ans,rt;
inline int dfs(int x,int fa){
	set <int> s;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa){
			int tmp=dfs(e[i].to,x);
			if(tmp==-1) return -1;
			else s.insert(tmp+1);
		}
	if(s.size()==0) return 0;
	if(s.size()==1) return *s.begin();
	if(s.size()>2) return -1;
	if(s.size()==2){
		if(fa==0) return *s.begin()+*s.rbegin();
		else{rt=x;return -1;}
	}
}
int main(){
	n=read();
	For(i,1,n-1){int x=read(),y=read();insert(x,y);}
	ans=dfs(1,0);
	if(ans==-1&&rt) ans=dfs(rt,0);
	while(ans%2==0) ans>>=1;
	printf("%d\n",ans);
	return 0;
}