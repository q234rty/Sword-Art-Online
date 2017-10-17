#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define mp make_pair
#define pa pair<ll,int>
#define int ll
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,w,k,a[N],t[N],G,r;
ll sum[N],ans;
multiset <int> s,s2;
inline bool check(int x){
	if(s.size()<w){
		if(G+(t[x]+1)/2<=k) return 1;
		else return 0;
	}else{
		if(*s.begin()>=t[x]){
			if(G+t[x]<=k) return 1;
			else return 0;
		}else{
			if(G+(*s.begin()/2)+(t[x]+1)/2<=k) return 1;
			else return 0;
		}
	}
}
inline void solve(int x){
	if(s.size()<w) s.insert(t[x]),G+=(t[x]+1)/2;
	else{
		if(*s.begin()>=t[x]){
			G+=t[x];
			s2.insert(t[x]);
		}else{
			G+=(t[x]+1)/2+(*s.begin()/2);
			s2.insert(*s.begin());
			s.erase(s.begin());
			s.insert(t[x]);
		}
	}
}
inline void del(int x){
	if(s.find(t[x])==s.end()){
		if(s2.find(t[x])==s2.end()) return;
		s2.erase(s2.find(t[x]));
		G-=t[x];
	}else{
		s.erase(s.find(t[x]));
		if(s2.size()>0) s.insert(*s2.rbegin()),G-=*s2.rbegin()/2,s2.erase(s2.find(*s2.rbegin()));
		G-=(t[x]+1)/2;
	}
}
main(){
	n=read();w=read();k=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) sum[i]=sum[i-1]+a[i];
	For(i,1,n) t[i]=read();
	For(i,1,n){
		if(i!=1) del(i-1);
		while(r+1<=n&&check(r+1)) r++,solve(r);
		ans=max(ans,sum[r]-sum[i-1]);
	}
	printf("%I64d\n",ans);
	return 0;
}
