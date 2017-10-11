#include<bits/stdc++.h>
#define inf 1e9
#define N 200005
#define M 40000005
#define mod 1000000007
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll read(){
	char ch=nc();ll sum=0;
	while(!(ch>='0'&&ch<='9'))ch=nc();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
	return sum;
}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int q[N],n,m,f[N],fa[N],c[N][2],mx[N],val[N],ans=inf,rev[N];
inline bool isroot(int x){
	return (c[fa[x]][0]!=x)&&(c[fa[x]][1]!=x);
}
inline void update(int x){
	int l=c[x][0],r=c[x][1];
	mx[x]=x;
	if(val[mx[l]]>val[mx[x]]) mx[x]=mx[l];
	if(val[mx[r]]>val[mx[x]]) mx[x]=mx[r];
}
inline void pushdown(int x){
	int l=c[x][0],r=c[x][1];
	if(rev[x]){
		rev[x]^=1;rev[l]^=1;rev[r]^=1;
		swap(c[x][0],c[x][1]);
	}
}
inline void rotate(int &x){
	int y=fa[x],z=fa[y],l,r;
	if(c[y][0]==x) l=0;else l=1;
	r=l^1;
	if(!isroot(y)){
		if(c[z][0]==y) c[z][0]=x;
		else c[z][1]=x;
	}
	fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
	c[y][l]=c[x][r];c[x][r]=y;
	update(y);update(x);
}
inline void splay(int &x){
	int top;q[top=1]=x;
	for(int i=x;!isroot(i);i=fa[i]) q[++top]=fa[i];
	while(top) pushdown(q[top--]);
	while(!isroot(x)){
		int y=fa[x],z=fa[y];
		if(!isroot(y)){
			if(c[y][0]==x^c[z][0]==x) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
inline void access(int x){
	for(int t=0;x;t=x,x=fa[x]) splay(x),c[x][1]=t,update(x);
}
inline void makeroot(int x){
	access(x);splay(x);rev[x]^=1;
}
inline void link(int x,int y){
	makeroot(x);fa[x]=y;
}
inline void cut(int x,int y){
	makeroot(x);access(y);splay(y);
	c[y][0]=fa[x]=0;update(y);
}
inline int query(int x,int y){
	makeroot(x);access(y);splay(y);
	return mx[y];
}
struct edge{int u,v,a,b;}e[100005];
inline bool operator <(edge a,edge b){return a.a<b.a;}
inline int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
int main(){
	n=read();m=read();
	For(i,1,n) f[i]=i;
	For(i,1,m) e[i]=(edge){read(),read(),read(),read()};
	sort(e+1,e+1+m);
	For(i,1,m){
		int u=e[i].u,v=e[i].v,a=e[i].a,b=e[i].b;
		if(find(u)==find(v)){
			int t=query(u,v);
			if(val[t]>b){
				cut(t,e[t-n].u);
				cut(t,e[t-n].v);
			}else{
				if(find(1)==find(n)) ans=min(ans,val[query(1,n)]+a);
				continue;
			}
		}else f[find(u)]=find(v);
		mx[i+n]=i+n;val[i+n]=b;
		link(u,i+n);link(v,i+n);
		if(find(1)==find(n)) ans=min(ans,val[query(1,n)]+a);
	}
	if(ans==inf) writeln(-1);
	else writeln(ans);
	return 0;
}