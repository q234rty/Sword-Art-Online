#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<set>
#include<map>
#include<queue>
#include<vector>
#define inf 1e9
#define mod 10007
#define N 405
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int cnt,f[N][N],n,m,head[N],in[N];
struct edge{int next,to;}e[N*N];
inline void insert(int u,int v){
	e[++cnt]=(edge){head[u],v};head[u]=cnt;in[v]++;
	e[++cnt]=(edge){head[v],u};head[v]=cnt;in[u]++;
}
double ans,a[N<<2],b[N<<2];
bool vis[N];
inline double solve(int x,int y,int z){
	memset(vis,0,sizeof vis);
	memset(a,0,sizeof a);
	vector <int> c;
	For(i,1,n) if(f[y][i]==z){
		for(int j=head[i];j;j=e[j].next){
			a[e[j].to]+=1.0/n/in[i];
			if(!vis[e[j].to]) vis[e[j].to]=1,c.push_back(e[j].to);
		}
	}
	double mx=0;
	For(i,1,n){
		double sum=0;
		int p=c.size();
		For(j,0,p-1){
			int k=c[j];
			b[f[i][k]]=max(b[f[i][k]],a[k]);
		}
		For(j,0,p-1){
			int k=c[j];
			sum+=b[f[i][k]],b[f[i][k]]=0;
		}
		mx=max(mx,sum);
	}
	return mx;
}
int main(){
	n=read();m=read();
	For(i,1,n) For(j,1,n) if(i!=j) f[i][j]=n+1;
	For(i,1,m){
		int x=read(),y=read();
		f[x][y]=1;f[y][x]=1;
		insert(x,y);
	}
	For(k,1,n) For(i,1,n) For(j,1,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	For(i,1,n){
		double sum=0;
		For(j,0,n){
			int cnt=0;
			For(k,1,n) if(f[i][k]==j) cnt++;
			if(!cnt) continue;
			sum+=max(1.0/n,solve(n,i,j));
		}
		ans=max(ans,sum);
	}
	printf("%.233lf",ans);
	return 0;
}