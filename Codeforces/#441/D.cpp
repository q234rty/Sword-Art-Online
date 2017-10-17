#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,a[N],fa[N],ans;
inline int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
int main(){
	n=read();
	For(i,1,n) a[i]=read();
	cout<<1<<" ";
	For(i,1,n) fa[i]=i;
	For(i,1,n){
		fa[a[i]]=a[i]-1;
		int p=find(n);
		ans=i+1-(n-p);
		cout<<ans<<" ";
	}
	return 0;
}