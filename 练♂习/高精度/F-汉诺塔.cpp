#include<bits/stdc++.h>
#define ll long long
#define N 1005
using namespace std;
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
char s1[N],s2[N];
int n,a[N],f[N],tot,cnt;
inline int cal(){
	int tot=0;
	For(i,0,n-1) tot=tot*10+s1[i]-48;
	return tot;
}
int main(){
	scanf("%s",s1);scanf("%s",s2);
	n=strlen(s2);
	For(i,0,n-1) a[n-i]=s2[i]-48;
	f[1]=tot=1;
	for(;n>1||a[1];cnt++){
		if(a[1]&1){
			For(i,1,tot) f[i]<<=1;
			For(i,1,tot) f[i+1]+=f[i]/10,f[i]%=10;
			if(f[tot+1]) tot++;
		}
		int p=0;
		Rep(i,n,1) p=p*10+a[i],a[i]=p>>1,p&=1;
		if(!a[n]) n--;
	}
	n=strlen(s1);
	if(n<=3&&cal()<cnt) puts("0");
	else Rep(i,tot,1) printf("%d",f[i]);
	return 0;
}