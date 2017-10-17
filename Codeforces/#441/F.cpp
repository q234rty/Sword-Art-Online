#include<bits/stdc++.h>
#define LL long long
#define N 200005
#define int LL
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,a[N],r[N],l[N],sum[N<<2];
inline void pushup(int k){
	sum[k]=sum[k<<1]|sum[k<<1|1];
}
inline void build(int k,int l,int r){
	if(l==r){sum[k]=a[l];return;}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
inline int query(int k,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[k];
	int mid=(l+r)>>1;
	if(y<=mid) return query(k<<1,l,mid,x,y);
	else if(x>mid) return query(k<<1|1,mid+1,r,x,y);
	else return query(k<<1,l,mid,x,mid)|query(k<<1|1,mid+1,r,mid+1,y);
}
main(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,2,n){
		l[i]=i-1;
		while(l[i]&&a[i]>=a[l[i]]) l[i]=l[l[i]];
	}
	r[n]=n+1;
	Rep(i,n-1,1){
		r[i]=i+1;
		while(r[i]!=n+1&&a[i]>a[r[i]]) r[i]=r[r[i]];
	}
//	For(i,1,n) cout<<l[i]<<" ";cout<<endl;
//	For(i,1,n) cout<<r[i]<<" ";cout<<endl;
	LL ans=0;
	build(1,1,n);
	For(i,1,n){
		int L=l[i]+1,R=r[i]-1;
		if(L==R)continue;
		int ll=L,rr=i-1,ans1=L-1;
		while(ll<=rr){
			int mid=(ll+rr)>>1;
			if(query(1,1,n,mid,i)!=a[i]) ans1=mid,ll=mid+1;
			else rr=mid-1;
		}
		ll=i+1;rr=R;int ans2=R+1;
		while(ll<=rr){
			int mid=(ll+rr)>>1;
			if(query(1,1,n,i,mid)!=a[i]) ans2=mid,rr=mid-1;
			else ll=mid+1;
		}
//		cout<<i<<endl;
//		cout<<ans1<<" "<<ans2<<endl;
//		cout<<L<<" "<<R<<endl;
//		cout<<endl;
		if(ans1!=L-1) ans+=1ll*(ans1-L+1)*(R-i+1);
		if(ans2!=R+1) ans+=1ll*(i-L+1)*(R-ans2+1);
		if(ans1!=L-1&&ans2!=R+1) ans-=1ll*(ans1-L+1)*(R-ans2+1);
	}
	printf("%I64d",ans);
	return 0;
}