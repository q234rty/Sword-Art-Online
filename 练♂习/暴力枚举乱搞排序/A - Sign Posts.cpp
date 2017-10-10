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
#define int ll
#define mod 10007
#define N 100005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int n,m,r[N];
struct data{int a,b,c;}a[N];
struct Ans{int x,y;}ans[6];
inline int calc(data x,data y,data z){
	return x.a*y.b*z.c+x.b*y.c*z.a+x.c*y.a*z.b;
}
inline void dfs(int n,int k){
	if(n<=m-k){
		puts("YES");writeln(k+n);
		For(i,1,k) printf("%I64d %I64d\n",ans[i].x,ans[i].y);
		For(i,1,n) printf("%I64d -1\n",r[i]);
		exit(0);
	}
	if(k==m) return;
	int g=m-k;
	int d[N];
	For(i,1,n) d[i]=r[i];
	Rep(T,g*g,0){
		int x=0,y=0,p=0;
		while(x==y) x=rand()%n+1,y=rand()%n+1;
		x=r[x];y=r[y];
		if(a[x].a*a[y].b==a[x].b*a[y].a) continue;
		For(i,1,n)
			if(calc(a[x],a[y],a[d[i]])!=calc(a[x],a[d[i]],a[y]))
				r[++p]=d[i];
		if(p>max(1.0*g-1,n*(1-1.0/(2*g)))) continue;
		ans[k+1]=(Ans){x,y};dfs(p,k+1);
	}
}
main(){
	srand(1000000007);
	n=read();m=read();
	For(i,1,n) a[i]=(data){read(),read(),read()};
	For(i,1,n) r[i]=i;
	dfs(n,0);
	puts("NO");
	return 0;
}