#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define mp make_pair
#define pa pair<ll,int>
#define int ll
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int k,n,m,a[N];
pa h[N];
int main(){
	k=read();n=read();m=read();
	For(i,1,k) a[i]=read();
	For(i,1,n){
		int opt=read(),x=read(),y=read();
		if(opt==1) if(h[x].first()>=y) 
	}
	return 0;
}