#include<bits/stdc++.h>
#define ll long long
#define inf 1e9
#define N 100005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int k,n,m,Q,ans;
bool dp[2][105][105];
int main(){
	n=read();m=read();k=read();Q=read();
	dp[0][0][0]=1;
	ans=Q;
	For(i,1,k){
		int sao=i&1,pre=sao^1;
		memset(dp[sao],0,sizeof dp[sao]);
		For(j,0,n) For(k,0,m) if(dp[pre][j][k]){
			if(j!=0) dp[sao][0][k]=1;
			if(k!=0) dp[sao][j][0]=1;
			if(j!=n) dp[sao][n][k]=1;
			if(k!=m) dp[sao][j][m]=1;
			if(j&&k<=m){
				if(m-k>j) dp[sao][0][j+k]=1;
				else dp[sao][j-(m-k)][m]=1;
			}
			if(k&&j<=n){
				if(n-j>k) dp[sao][j+k][0]=1;
				else dp[sao][n][k-(n-j)]=1;
			}
		}
		For(j,0,n) For(k,0,m) if(dp[sao][j][k]) ans=min(ans,abs(j+k-Q));
	}
	printf("%d\n",ans);
	return 0;
}