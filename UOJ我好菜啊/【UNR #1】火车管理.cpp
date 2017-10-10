#include<bits/stdc++.h>
#define inf 1e9
#define N 500005
#define M 8000005
#define mod 1000000007
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int n,m,type,ans,ind,root[N],p;
int val[M],ls[M],rs[M];
struct tree{int sum,tag;}t[N<<2];
inline void pushdown(int k,int l,int r){
	int tag=t[k].tag;t[k].tag=0;
	if(l==r||!tag) return;
	int mid=(l+r)>>1;
	t[k<<1].sum=
}
inline int query(int k,int l,int r,int x,int y){
	if(l==x&&r==y) return t[k].sum;
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	if(y<=mid) return query(k<<1,l,mid,x,y);
	else if(x>mid) return query(k<<1|1,mid+1,r,x,y);
	else return query(k<<1,l,mid,x,mid)+query(k<<1|1,mid+1,r,mid+1,y);
}
int main(){
	n=read();m=read();type=read();
	while(m--){
		int opt=read();
		if(opt==1){
			int x=read(),y=read();
			x=(x+ans*type)%n+1;y=(y+ans*type)%n+1;
			if(x>y) swap(x,y);
			ans=query(1,1,n,x,y);
			writeln(ans);
		}else if(opt==2){
			int x=read();
			Del(1,1,n,x);
		}else{
			int x=read(),y=read(),val=read();
			x=(x+ans*type)%n+1;y=(y+ans*type)%n+1;
			if(x>y) swap(x,y);
			++tot;val[tot]=x;
			insert(1,1,n,x,y,tot);
		}
	}
	return 0;
}