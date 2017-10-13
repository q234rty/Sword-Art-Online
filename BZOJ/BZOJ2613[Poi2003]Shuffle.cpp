#include<bits/stdc++.h>
#define inf 1e9
#define N 1000005
#define ll long long
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int n,k,a[N],b[N],top,q[N];
bool vis[N];
int main(){
	n=read();k=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) if(!vis[x]){
		int x=i;top=0;
		while(!vis[x]){
			vis[x]=1;
			q[++top]=x;
			x=a[x];
		}
		int p=k%top;
		For(j,1,top) a[q[j]]
	}
	For(i,1,n) writeln(a[i]);
	return 0;
}