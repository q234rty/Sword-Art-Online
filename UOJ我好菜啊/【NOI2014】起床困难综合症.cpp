#include<bits/stdc++.h>
#define inf 1e9
#define N 200005
#define M 40000005
#define mod 1000000007
#define int ll
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int bin[32],n,m,ans;
struct data{
	int opt,x;
	int solve(int y){
		if(opt==1) return x&y;
		else if(opt==2) return x|y;
		else return x^y;
	}
}a[N];
inline int solve(int x){
	For(i,1,n) x=a[i].solve(x);
	return x;
}
main(){
	bin[0]=1;For(i,1,31) bin[i]=bin[i-1]<<1;
	n=read();m=read();
	For(i,1,n){
		char s[5];scanf("%s",s);
		if(s[0]=='A') a[i].opt=1;
		else if(s[0]=='O') a[i].opt=2;
		else a[i].opt=3;
		a[i].x=read();
	}
	Rep(i,31,0) if(bin[i]<=m){
		if(solve(0)&bin[i]) continue;
		if(ans+bin[i]<=m&&(solve(bin[i])&bin[i])) ans+=bin[i];
	}
	writeln(solve(ans));
	return 0;
}