#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<set>
#include<map>
#include<bitset>
#include<queue>
#include<vector>
#include<time.h>
#include<iostream>
#define inf 1e9
#define mod 1000000007
#define N 1000005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int root,f[N<<2],g[N<<2],cnt,bin[N],fa[N<<2];
int l[N<<2],r[N<<2];
inline int make(int p=-1){
	fa[cnt]=p;
	l[cnt]=r[cnt]=-1;
	g[cnt]=0;f[cnt]=1;
	cnt++;
	return cnt-1;
}
inline void nan(int x,int tim){
	if(!tim) return;
	g[x]+=tim-(f[x]==1);
	f[x]=1ll*f[x]*bin[tim]%mod;
}
inline void add(int x){
	if(l[x]==-1) l[x]=make(x);
	if(r[x]==-1) r[x]=make(x);
}
inline void push(int x){
	add(x);
	nan(l[x],g[x]);
	nan(r[x],g[x]);
	g[x]=0;
}
char s[N];
int main(){
	bin[0]=1;For(i,1,N-1) bin[i]=(bin[i-1]<<1)%mod;
	int T=read();
	while(T--){
		int Q=read();cnt=0;
		root=make();f[root]=2;
		while(Q--){
			int opt=read();
			if(opt==1){
				int x=read();
				nan(root,x);
			}else{
				scanf("%s",s+1);
				int p=strlen(s+1);
				int x=root;
				For(i,1,p){
					push(x);
					if(s[i]=='L') x=l[x];
					else x=r[x];
				}
				if(l[fa[x]]==x) l[fa[x]]=-1;
				else r[fa[x]]=-1;
				x=fa[x];
				while(x!=-1){
					f[x]=0;
					if(l[x]==-1) f[x]=(f[x]+1)%mod;
					else f[x]=(f[x]+f[l[x]])%mod;
					if(r[x]==-1) f[x]=(f[x]+1)%mod;
					else f[x]=(f[x]+f[r[x]])%mod;
					x=fa[x];
				}
			}
			writeln((f[root]-1+mod)%mod);
		}
	}
	return 0;
}