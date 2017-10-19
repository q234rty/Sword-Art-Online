#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define For(i,x,id) for(int i=x;i<=id;i++)
#define Rep(i,x,id) for(int i=x;i>=id;i--)
#define mp make_pair
#define inf 1e15
#define pa pair<int,int>
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
int n,m,k,vis[N],a[N],l[4],p[4];
ll b[4][N];
int main(){
	n=read();m=read();k=read();
	For(i,1,n) a[i]=read();
	int n1=read();For(i,1,n1) vis[read()]|=1;
	int n2=read();For(i,1,n2) vis[read()]|=2;
	For(i,1,n) b[vis[i]][++l[vis[i]]]=a[i];
	For(i,0,3) sort(b[i]+1,b[i]+1+l[i]);
	For(i,0,3) b[i][l[i]+1]=inf,p[i]=1;	
/*	For(i,0,3){
		For(j,1,l[i]) cout<<b[i][j]<<" ";
		cout<<endl;
	}*/
	ll ans=inf,res=0,sum=0;
	For(i,0,min(m,l[3])){
		if(k-i>l[1]||k-i>l[2]) continue;
		while(p[3]<=i) res+=b[3][p[3]++],sum++;
		if(p[1]==k-i+2) res-=b[1][--p[1]],sum--;
		while(p[1]<=k-i) res+=b[1][p[1]++],sum++;
		if(p[2]==k-i+2) res-=b[2][--p[2]],sum--;
		while(p[2]<=k-i) res+=b[2][p[2]++],sum++;
		while(sum<m){
			ll M=inf;
			For(j,0,3) if(p[j]<=l[j]) M=min(M,b[j][p[j]]);
			if(M==inf) break;
			For(j,0,3) if(b[j][p[j]]==M){res+=b[j][p[j]++];break;}
			sum++;
		}
		if(sum==m) ans=min(ans,res);
	}
	if(ans==inf) puts("-1");
	else printf("%I64d",ans);
	return 0;
}
