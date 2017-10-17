#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define For(i,x,id) for(int i=x;i<=id;i++)
#define Rep(i,x,id) for(int i=x;i>=id;i--)
#define mp make_pair
#define inf 1e15
#define pa pair<int,int>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,b[4][N],m,k,vis[N],a[N],tot[4],pos[4];
ll sum[4][N];
inline int check(int t,int x,int y){
	
}
int main(){
	n=read();m=read();k=read();
	For(i,1,n) a[i]=read();
	int n1=read();
	For(i,1,n1) vis[read()]|=1;
	int n2=read();
	For(i,1,n2) vis[read()]|=2;
	For(i,1,n) b[vis[i]][++tot[vis[i]]]=v[i];
	For(i,0,3) sort(b[i]+1,b[i]+1+tot[i]);
	For(i,0,3) For(j,1,tot[i]) s[i][j]=s[i][j-1]+b[i][j];
	ll ans=inf;
	for(int i=0;i<=k&&i<=tot[3];i++){
		if(k-i>min(tot[1],tot[2])||k*2-i>m) continue;
		int l=0,r=1e9,Ans;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i,k-i)>=m) Ans=mid,r=mid-1;
			else l=mid+1;
		}
	}
	if(ans==inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}