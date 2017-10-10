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
#include<time.h>
#include<iostream>
#define inf 1e9
#define int ll
#define mod 998244353
#define N 200005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
struct data{
	int l,r,y,val;
	bool operator <(const data &a)const{
		return y<a.y;
	}
}e[N];
ll ans[N];
int n,tot,cnt[N],xx[N],last[N],k;
signed main(){
	n=read();k=read();
	For(i,1,n){
		int x=read(),y=read();
		xx[++tot]=x;
		e[tot]=(data){x,x+k,y,1};
		xx[++tot]=x+k;
		e[tot]=(data){x,x+k,y+k,-1};
	}
	int m=1;
	sort(xx+1,xx+1+tot);
	For(i,2,tot) if(xx[i]!=xx[m]) xx[++m]=xx[i];
	tot=m;
	For(i,1,n) last[i]=-inf; 
	sort(e+1,e+1+n*2);
	For(i,1,2*n){
		int l=upper_bound(xx+1,xx+tot+1,e[i].l)-xx;
		int r=lower_bound(xx+1,xx+tot+1,e[i].r)-xx;
		For(j,l,r){
			ans[cnt[j]]+=(e[i].y-last[j])*(xx[j]-xx[j-1]);
			cnt[j]+=e[i].val;
			last[j]=e[i].y;
		}
	}
	For(i,1,n) printf("%I64d ",ans[i]);
	return 0;
}