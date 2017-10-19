#include<bits/stdc++.h>
#define ll long long
#define N 20
#define oo 1e9
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i<y;i++)
#define mp make_pair
#define pa pair<ll,int>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m,G[N][N],f[1<<N][N],s[1<<N],sum;
int main(){
	n=read();m=read();
	For(i,1,m){int x=read()-1,y=read()-1;G[x][y]=G[y][x]=read();sum+=G[x][y];}
	Rep(i,0,1<<n) Rep(j,0,n) if((i>>j)&1) Rep(k,j+1,n) if((i>>k)&1) s[i]+=G[j][k];
	Rep(i,0,1<<n) Rep(j,0,n) f[i][j]=-oo;
	Rep(i,0,1<<n) if(i&1) f[i][0]=s[i];
	Rep(i,0,1<<n) Rep(j,0,n) if((i>>j)&1) for(int k=i;k;k=(k-1)&i) if(k&1) Rep(l,0,n) if(((k>>l)&1)&&((~k>>j)&1)&&G[l][j]) f[i][j]=max(f[i][j],f[k][l]+G[l][j]+s[i^k]);
	printf("%d\n",sum-f[(1<<n)-1][n-1]);
	return 0;
}
