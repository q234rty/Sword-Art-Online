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
char s[N];
int a[N],b[N],c[N];
inline void solve(){
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	b[0]=c[0]=1;
	b[1]=1;c[1]=0;
	for(;a[0]||a[1];){
		if(a[1]&1){
			c[0]=max(c[0],b[0]);
			For(i,1,c[0]) c[i]=b[i]+c[i];
			For(i,1,c[0]) c[i+1]+=c[i]/10,c[i]%=10;
			if(c[c[0]+1]) c[0]++;
		}else{
			b[0]=max(c[0],b[0]);
			For(i,1,b[0]) b[i]=b[i]+c[i];
			For(i,1,b[0]) b[i+1]+=b[i]/10,b[i]%=10;
			if(b[b[0]+1]) b[0]++;
		}
		int z=0;
		Rep(i,a[0],1) z=z*10+a[i],a[i]=z>>1,z&=1;
		if(!a[a[0]]) a[0]--;
	}
	Rep(i,c[0],1) printf("%d",c[i]);
	puts("");
}
int main(){
	int T=read();
	while(T--){
		scanf("%s",s);
		a[0]=strlen(s);
		For(i,0,a[0]-1) a[a[0]-i]=s[i]-48;
		solve();
	}
	return 0;
}