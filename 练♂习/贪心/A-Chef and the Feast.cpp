#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define int ll
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define mp make_pair
#define pa pair<ll,int>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,a[N],b[N],top;
inline bool cmp(int x,int y){return x>y;}
main(){
	int T=read();
	while(T--){
		n=read();ll mx2=0,mx=0,mn=0,ans=0;
		For(i,1,n) a[i]=read();
		For(i,1,n) if(a[i]>=0) mx+=a[i],mx2++;
		top=0;
		For(i,1,n) if(a[i]<0) mn+=a[i],b[++top]=a[i];
		sort(b+1,b+1+top,cmp);
		ans=mx*mx2+mn;
		For(i,1,top)
			if(ans<(mx+b[i])*(mx2+1)+mn-b[i]) ans=(mx+b[i])*(mx2+1)+mn-b[i],mx2++,mx+=b[i],mn-=b[i];
			else break;
		printf("%lld\n",ans);
	}
	return 0;
}
