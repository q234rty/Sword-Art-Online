#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define mp make_pair
#define pa pair<ll,int>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,h,in[405],ou[405],fa[405];
bool flag[405];
inline int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
int main(){
	n=read();h=read();
	For(i,1,h*2) fa[i]=i;
	For(i,1,n){
		int a=read(),b=read(),c=read(),d=read();
		int l=(c==0)?h+a:c;
		int r=(d==0)?b:h+d;
		in[r]++;ou[l]++;
		fa[find(l)]=find(r);
	}
	For(i,1,h) if(ou[i]>in[i]){puts("NO");return 0;}
	For(i,h+1,h*2) if(ou[i]<in[i]){puts("NO");return 0;}
	For(i,1,h*2) if(in[i]!=ou[i]) flag[find(i)]=1;
	For(i,1,h*2) if(find(i)==i&&!flag[i]&&in[i]+ou[i]!=0){puts("NO");return 0;}
	puts("YES");
	return 0;
}