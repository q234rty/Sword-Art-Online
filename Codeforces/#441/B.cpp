#include<bits/stdc++.h>
#define ll long long
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
int n,k,m,a[N],f[N];
int main(){
	n=read();k=read();m=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) f[a[i]%m]++;
	For(i,0,100000) if(f[i]>=k){
		puts("Yes");
		int py=0;
		For(j,1,n){
			if(a[j]%m==i) cout<<a[j]<<" ",py++;
			if(py==k) return 0;
		}
	}
	puts("No");
	return 0;
}