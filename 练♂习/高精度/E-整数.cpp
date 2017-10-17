#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
#define N 1000005
#define int ll
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
set <int> A,B;
int now[N];
inline void add(int x,ll y){
	if(!y) return;
	if(now[x]<0) A.erase(x);
	else if(now[x]>0) B.erase(x);
	now[x]+=y;
	if(now[x]<=-(1ll<<60)) now[x]+=(1ll<<60),add(x+1,-1);
	if(now[x]>=(1ll<<60)) now[x]-=(1ll<<60),add(x+1,1);
	if(now[x]<0) A.insert(x);
	else if(now[x]>0) B.insert(x);
}
main(){
	int n=read();int t=read();t=read();t=read();
	A.insert(-inf);B.insert(-1);
	while(n--){
		int opt=read();
		if(opt==1){
			int a=read(),b=read();
			int x=b/60,y=b%60;
			int tmp=abs(a),flag=((a<0)?-1:1);
			add(x,flag*((tmp&((1ll<<(60-y))-1))<<y));
			add(x+1,flag*(tmp>>(60-y)));
		}else{
			int a=read();
			int x=a/60,y=a%60;
			ll val=now[x];
			if(*(--A.lower_bound(x))>*(--B.lower_bound(x))) val--;
			printf("%lld\n",(val>>y)&1);
		}
	}
	return 0;
}