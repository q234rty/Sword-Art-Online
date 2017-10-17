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
int n,m,k=1,T,ans[N*10],top;
int main(){
	m=n=read();
	while(k*10<=m) k*=10;
	while(1){
		int x=n,Ans=n,T=0;
		while(x) Ans+=x%10,x/=10,T++;
		if(Ans==m) ans[++top]=n;
		n--;
//		cout<<n<<" "<<T<<endl;
		if(n<k) k/=10;
		if(n==0||n+T*9<m) break;
	}
	cout<<top<<endl;
	Rep(i,top,1) cout<<ans[i]<<endl;
	return 0;
}