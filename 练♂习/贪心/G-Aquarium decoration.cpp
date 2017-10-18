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
int n,m,k,rk[N],vis[N];
struct data{
	int x,id;
	bool operator <(const data &a)const{
		return x<a.x;
	}
}a[N];
multiset <int> A,B,C,D;
int main(){
	n=read();m=read();k=read();
	For(i,1,n) a[i]=(data){read(),i};
	sort(a+1,a+1+n);
	For(i,1,n) rk[a[i].id]=i;
	int n1=read();
	For(i,1,n1) vis[rk[read()]]|=1;
	int n2=read();
	For(i,1,n2) vis[rk[read()]]|=2;
	For(i,1,n){
		if(vis[i]==0) D.insert(a[i].x);
		if(vis[i]==1) B.insert(a[i].x);
		if(vis[i]==2) C.insert(a[i].x);
		if(vis[i]==3) A.insert(a[i].x);
	}
	For(x,0,k){
		if(2*k-i>m||)
	}
	return 0;
}