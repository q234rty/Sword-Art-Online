#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define base 23333
#define mod 1000000007
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
inline void write(int x){
	if(x<10) putchar(x+48);
	else write(x/10),putchar(x%10+48);
}
inline void writeln(int x){
	write(x);putchar('\n');
}
char s1[N],s2[N];
int n,m,hah[26][N],ans[N],Hah[26][N],Pow[N],vis[26];
int main(){
	n=read();m=read();
	scanf("%s%s",s1+1,s2+1);
	For(i,0,25) For(j,1,n) hah[i][j]=(1ll*hah[i][j-1]*base+((s1[j]-'a'==i)?3:0))%mod;
	For(i,0,25) For(j,1,m) Hah[i][j]=(1ll*Hah[i][j-1]*base+((s2[j]-'a'==i)?3:0))%mod;
	Pow[0]=1;For(i,1,n) Pow[i]=1ll*Pow[i-1]*base%mod;
	For(i,m,n){
		int l=i-m+1,r=i,flag=1;
		For(j,0,25) vis[j]=-1;
		For(j,0,25){
			int x=(1ll*hah[j][r]-1ll*hah[j][l-1]*Pow[r-l+1]%mod+mod)%mod;
			if(!x) continue;
			int f=-1;
			For(k,0,25) if(x==Hah[k][m]&&!(vis[k]>=0&&vis[k]!=j)){f=k;break;}
			if(f==-1) flag=0;
			else vis[j]=f,vis[f]=j;
			if(!flag) break;
		}
		if(flag) For(j,0,25) if(vis[j]>=0&&vis[vis[j]]!=j){flag=0;break;}
		if(flag) ans[++ans[0]]=i-m+1;
	}
	writeln(ans[0]);
	For(i,1,ans[0]) write(ans[i]),putchar(' ');
	return 0;
}
