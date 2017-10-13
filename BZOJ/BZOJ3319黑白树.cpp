#include<bits/stdc++.h>
#define ll long long
#define N 1000005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	char ch=nc();int sum=0;
	while(!(ch>='0'&&ch<='9'))ch=nc();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
	return sum;
}
inline void write(int x){
	if(x<10) putchar(x+48);
	else write(x/10),putchar(x%10+48);
}
inline void writeln(int x){
	if(x<0) x=-x,putchar('-');
	write(x);putchar('\n');
}
int n,m,head[N],cnt,c[N<<1],fa[N],f[N],mark[N],dep[N];
inline int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
struct edge{int from,next,to;}e[N<<1];
struct data{int u,v;}E[N];
struct que{int opt,u,v;}q[N];
vector <int> t[N];
inline void insert(int u,int v,int x){
	e[++cnt]=(edge){u,head[u],v};head[u]=cnt;c[cnt]=x;
	e[++cnt]=(edge){v,head[v],u};head[v]=cnt;c[cnt]=x;
}
inline void dfs(int x){
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			E[c[i]]=(data){x,e[i].to};
			mark[e[i].to]=c[i];
			dfs(e[i].to);
		}
}
int rs[N],tot,ans[N];
inline void change(int u,int v,int x){
	while(u!=v){
		if(dep[u]<dep[v]) swap(u,v);
		if(!rs[u]) rs[u]=x,f[u]=f[fa[u]],t[x].push_back(u);
		u=f[u];
	}
}
inline void solve(int x){
	for(int i=0;i<t[x].size();i++){
		int p=t[x][i];
		f[p]=f[fa[p]];
	}
}
int main(){
	n=read();m=read();
	For(i,1,n-1){
		int u=read(),v=read();
		insert(u,v,i);
	}
	dfs(1);
	For(i,1,n) f[i]=i;
	For(i,1,m){
		q[i]=(que){read(),read()};
		if(q[i].opt==2) q[i].v=read();
	}
	For(i,1,m) if(q[i].opt==2) change(q[i].u,q[i].v,i);
	For(i,1,n) f[i]=i;
	For(i,2,n) if(!rs[i]){
		int t=mark[i];
		f[find(E[t].v)]=find(E[t].u);
	}
	Rep(i,m,1){
		if(q[i].opt==1){
			int p=find(q[i].u);
			if(p==1) ans[++tot]=0;
			else ans[++tot]=mark[p];
		}else solve(i);
	}
	Rep(i,tot,1) writeln(ans[i]);
	return 0;
}