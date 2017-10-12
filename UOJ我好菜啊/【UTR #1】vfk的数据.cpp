#include<bits/stdc++.h>
#define inf 1e9
#define N 500005
#define M 1000005
#define mod 1000000007
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef unsigned long long ll;
inline ll read(){ll x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
ll g,l;
int main(){
	ll T=read();
	while(T--){
		g=read();l=read();
		ll mx=g+l;
		l=l/g;ll mn=(ll)sqrt(l)*g;
		printf("%llu %llu\n",mn*2,mx);
	}
}