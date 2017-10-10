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
#define N 100005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int n,k,x[N],y[N],l,r,L,R;
ll ans=1000000000000000000ll;
bool f[N];
struct data{
	int x,i;
	bool operator <(const data &a)const{
		return x<a.x;
	}
}a[N],b[N];
inline void dfs(int x){
	if(x>k){
		int rosl=l,rosr=r,rosL=L,rosR=R;
		while(f[a[l].i]) l++;
		while(f[b[L].i]) L++;
		while(f[a[r].i]) r--;
		while(f[b[R].i]) R--;
		int delx=a[r].x-a[l].x;
		int dely=b[R].x-b[L].x;
		if(!delx) delx++;
		if(!dely) dely++;
		if(delx&1) delx++;
		if(dely&1) dely++;
//		cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
//		cout<<delx<<" "<<dely<<endl;
//		cout<<endl;
		ans=min(ans,1ll*delx/2*dely/2);
		l=rosl,r=rosr,L=rosL,R=rosR;
		return;
	}
	int ros;

	ros=l;
	while(f[a[l].i]) l++;
	f[a[l].i]=1;l++;
	dfs(x+1);
	f[a[l-1].i]=0;l=ros;

	ros=L;
	while(f[b[L].i]) L++;
	f[b[L].i]=1;L++;
	dfs(x+1);
	f[b[L-1].i]=0;L=ros;

	ros=r;
	while(f[a[r].i]) r--;
	f[a[r].i]=1;r--;
	dfs(x+1);
	f[a[r+1].i]=0;r=ros;
	
	ros=R;
	while(f[b[R].i]) R--;
	f[b[R].i]=1;R--;
	dfs(x+1);
	f[b[R+1].i]=0;R=ros;

}
main(){
	n=read();k=read();
	For(i,1,n){
		int xx=read(),yy=read();
		int Xx=read(),Yy=read();
		x[i]=Xx+xx;y[i]=Yy+yy;
	}
	For(i,1,n) a[i]=(data){x[i],i};
	For(i,1,n) b[i]=(data){y[i],i};
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	l=L=1;r=R=n;
	dfs(1);
	writeln(ans);
	return 0;
}