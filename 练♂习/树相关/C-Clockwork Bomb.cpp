#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define pb push_back
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i<y;i++)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int f[N],fa[2][N],n,cnt;
inline int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
vector <int> e[2][N];
struct data{int x,y,xx,yy;}ans[N];
inline void dfs(int id,int x,int F){
	Rep(i,0,e[id][x].size()){
		int y=e[id][x][i];
		if(y==F) continue;
		fa[id][y]=x;dfs(id,y,x);
	}
}
inline void dfs(int x,int F){
	Rep(i,0,e[0][x].size()){
		int y=e[0][x][i];
		if(y==F) continue;
		dfs(y,x);
		if(fa[1][x]!=y&&fa[1][y]!=x) ans[++cnt]=(data){x,y,find(y),fa[1][find(y)]};
	}
}
int main(){
	n=read();
	For(i,1,n-1){int x=read(),y=read();e[0][x].pb(y);e[0][y].pb(x);}
	For(i,1,n-1){int x=read(),y=read();e[1][x].pb(y);e[1][y].pb(x);}
	dfs(0,1,0);dfs(1,1,0);
	For(i,2,n){
		int u=fa[1][i];
		if(fa[0][u]==i||fa[0][i]==u) f[i]=u;
		else f[i]=i;
	}
	dfs(1,0);
	printf("%d\n",cnt);
	For(i,1,cnt) printf("%d %d %d %d\n",ans[i].x,ans[i].y,ans[i].xx,ans[i].yy);
	return 0;
}