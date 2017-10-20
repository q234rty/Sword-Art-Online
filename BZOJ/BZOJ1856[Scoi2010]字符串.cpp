#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define mod 20100403
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m;
inline int ksm(int x,int y){
	int sum=1;
	while(y){
		if(y&1) sum=1ll*sum*x%mod;
		y>>=1;
		if(y) x=1ll*x*x%mod;
	}
	return sum;
}
inline int C(int n,int m){
	int res=1,res2=1;
	For(i,m+1,n) res=1ll*res*i%mod;
	For(i,1,n-m) res2=1ll*res2*i%mod;
	return 1ll*res*ksm(res2,mod-2)%mod;
}
int main(){
	n=read();m=read();
	printf("%d\n",(C(n+m,n)-C(n+m,m-1)+mod)%mod);
	return 0;
}