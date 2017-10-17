#include<bits/stdc++.h>
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,a,b,c,ans;
int main(){
	n=read();a=read();b=read();c=read();
	ans=min((n-1)*a,(n-1)*b);
	if(n>=2) ans=min(ans,a+(n-2)*c);
	if(n>=2) ans=min(ans,b+(n-2)*c);
	printf("%d\n",ans);
	return 0;
}