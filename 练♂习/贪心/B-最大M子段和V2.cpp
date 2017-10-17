#include<bits/stdc++.h>
#define ll long long
#define N 50005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define mp make_pair
#define int ll
#define pa pair<ll,int>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m,k,l[N],r[N];
ll ans,a[N];
set <pa> s;
inline void del(int x){
	int L=l[x],R=r[x];
	if(L) r[L]=R;
	if(R) l[R]=L;
}
main(){
	m=read();k=read();
	int sum=0,p=0;
	For(i,1,m){
		int x=read();
		if(!x) continue;
		if((sum<0&&x>0)||(sum>0&&x<0)){
			a[++n]=sum;
			p+=(sum>0);
			s.insert(mp(abs(sum),n));
			sum=0;
		}
		sum+=x;
		if(x>0) ans+=x;
	}
	if(sum) a[++n]=sum,s.insert(mp(abs(sum),n)),p+=(sum>0);
	For(i,1,n) l[i]=i-1,r[i]=i+1;
	r[n]=0;
	while(p>k){
		int x=s.begin()->second;
		s.erase(s.begin());
		if((a[x]<0)&&(!l[x]||!r[x])||!a[x]) continue;
		ans-=abs(a[x]);
		a[x]+=a[l[x]]+a[r[x]];
		s.erase(mp(abs(a[l[x]]),l[x]));
		s.erase(mp(abs(a[r[x]]),r[x]));
		del(l[x]);del(r[x]);
		s.insert(mp(abs(a[x]),x));
		p--;
	}
	printf("%lld\n",ans);
	return 0;
}