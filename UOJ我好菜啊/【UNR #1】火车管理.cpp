#include<bits/stdc++.h>
#define inf 1e9
#define N 500005
#define M 40000005
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
inline int merge(int x,int y){
	if(!x) return y;
	if(!y) return x;
	++ind;ls[ind]=x;rs[ind]=y;
	val[ind]=val[x];
	return ind;
}
inline void pushdown(int k,int l,int r){
	int tag=t[k].tag;t[k].tag=0;
	if(!tag) return;
	int mid=(l+r)>>1;
	t[k<<1].tag=merge(tag,t[k<<1].tag);
	t[k<<1|1].tag=merge(tag,t[k<<1|1].tag);
	t[k<<1].sum=val[tag]*(mid-l+1);
	t[k<<1|1].sum=val[tag]*(r-mid);
}
inline void insert(int k,int l,int r,int x,int y,int c){
	if(l==x&&r==y){
		t[k].tag=merge(c,t[k].tag);
		t[k].sum=(r-l+1)*val[c];
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	if(y<=mid) insert(k<<1,l,mid,x,y,c);
	else if(x>mid) insert(k<<1|1,mid+1,r,x,y,c);
	else insert(k<<1,l,mid,x,mid,c),insert(k<<1|1,mid+1,r,mid+1,y,c);
	t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
}
inline int query(int k,int l,int r,int x,int y){
	if(l==x&&r==y) return t[k].sum;
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	if(y<=mid) return query(k<<1,l,mid,x,y);
	else if(x>mid) return query(k<<1|1,mid+1,r,x,y);
	else return query(k<<1,l,mid,x,mid)+query(k<<1|1,mid+1,r,mid+1,y);
}
inline int erase(int &x){
	int y=x;x=++ind;
	ls[x]=ls[y];rs[x]=rs[y];
	val[x]=val[y]; 
	if(!ls[x]){x=0;return 1;}
	if(erase(ls[x])==1) x=rs[x];
	else val[x]=val[ls[x]];
	return 0;
}
inline void Del(int k,int l,int r,int x){
	if(l==r){
		if(t[k].tag){
			erase(t[k].tag);
			t[k].sum=val[t[k].tag];
		}
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) Del(k<<1,l,mid,x);
	else Del(k<<1|1,mid+1,r,x);
	t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
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
			x=(x+ans*type)%n+1;
			Del(1,1,n,x);
		}else{
			int x=read(),y=read(),v=read();
			x=(x+ans*type)%n+1;y=(y+ans*type)%n+1;
			if(x>y) swap(x,y);
			++ind;val[ind]=v;
			insert(1,1,n,x,y,ind);
		}
	}
	return 0;
}