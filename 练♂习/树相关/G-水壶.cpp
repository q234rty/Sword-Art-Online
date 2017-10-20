#include<bits/stdc++.h>
#define ll long long
#define N 2005
#define M 200005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m,p,q,f[M],bl[N][N],d[N][N],T;
char s[N][N];
struct data{int x,y,bl;};
queue <data> Q;
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
struct Edge{int x,y,val;}E[20000005];
inline bool operator <(Edge a,Edge b){return a.val<b.val;}
inline int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
inline void bfs(){
	while(!Q.empty()){
		data x=Q.front();Q.pop();
		For(i,0,3){
			int xx=x.x+dx[i],yy=x.y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m||s[xx][yy]=='#') continue;
			if(!bl[xx][yy]) bl[xx][yy]=x.bl,d[xx][yy]=d[x.x][x.y]+1,Q.push((data){xx,yy,x.bl});
			else if(bl[xx][yy]!=x.bl){
				E[++T]=(Edge){bl[xx][yy],x.bl,d[x.x][x.y]+d[xx][yy]};
			}
		}
	}
}
int head[M],cnt,fa[M][21],bin[21],mx[M][21];
struct edge{int next,to,w;}e[M<<1];
inline void insert(int u,int v,int w){
	e[++cnt]=(edge){head[u],v,w};head[u]=cnt;
	e[++cnt]=(edge){head[v],u,w};head[v]=cnt;
}
inline void doit(){
	sort(E+1,E+1+T);
	For(i,1,T){
		int u=find(E[i].x),v=find(E[i].y);
		if(find(u)!=find(v)){
			f[u]=v;
//			cout<<E[i].x<<" "<<E[i].y<<" "<<E[i].val<<endl;
			insert(E[i].x,E[i].y,E[i].val);
		}
	}
}
int dep[M];
bool vis[M];
inline void dfs(int x){
	vis[x]=1;
	For(i,1,20){
		if(bin[i]>dep[x]) break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
		mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
	}
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			mx[e[i].to][0]=e[i].w;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
}
inline int query(int x,int y){
	if(find(x)!=find(y)) return -1;
	if(dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y],Mx=0;
	For(i,0,20) if(del&bin[i]) Mx=max(Mx,mx[x][i]),x=fa[x][i];
	Rep(i,20,0) if(fa[x][i]!=fa[y][i]) Mx=max(Mx,max(mx[x][i],mx[y][i])),x=fa[x][i],y=fa[y][i];
	if(x==y) return Mx;
	return max(Mx,max(mx[x][0],mx[y][0]));
}
int main(){
	bin[0]=1;For(i,1,20) bin[i]=bin[i-1]<<1;
	n=read();m=read();p=read();q=read();
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,p){
		int x=read(),y=read();f[i]=i;
		bl[x][y]=i;Q.push((data){x,y,i});
	}
	bfs();doit();
/*	For(i,1,n){
		For(j,1,m) cout<<d[i][j]<<" ";
		cout<<endl;
	}*/
	For(i,1,p) if(!vis[i]) dfs(i);
//	cout<<dep[2]<<" "<<dep[4]<<endl;
	while(q--){int x=read(),y=read();printf("%d\n",query(x,y));}
	return 0;
}
