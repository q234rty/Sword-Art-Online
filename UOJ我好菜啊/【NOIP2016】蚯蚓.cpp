#include<bits/stdc++.h>
#define inf 1e9
#define N 100005
#define M 8000005
#define ll long long
#define mod 1000000007
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	char ch=nc();int sum=0;
	while(!(ch>='0'&&ch<='9'))ch=nc();
	while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
	return sum;
}inline void write(int x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(int x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int n,m,l,u,v,T,a[N],q[3][M],h[3],t[3],tag;
bool flag;
inline bool cmp(int x,int y){return x>y;}
int main(){
	n=read();m=read();l=read();u=read();v=read();T=read();
	For(i,1,n) a[i]=read();
	memset(q,-127,sizeof q);
	For(i,1,n) q[0][i]=a[i];
	sort(q[0]+1,q[0]+1+n,cmp);
	h[0]=h[1]=h[2]=1;
	t[1]=t[2]=0;t[0]=n;
	For(i,1,m){
		int mx=0;
		if(q[mx][h[mx]]<q[1][h[1]]) mx=1;
		if(q[mx][h[mx]]<q[2][h[2]]) mx=2;
		int x=q[mx][h[mx]++]+tag;
		if(i%T==0){
			if(!flag) flag=1;
			else putchar(' ');
			write(x);
		}
		int l1=1ll*x*u/v;
		int l2=x-l1;
		if(l1<l2) swap(l1,l2);
		tag+=l;
		q[1][++t[1]]=l1-tag;
		q[2][++t[2]]=l2-tag;
	}
	putchar('\n');
	flag=0;
	For(i,1,n+m){
		int mx=0;
		if(q[mx][h[mx]]<q[1][h[1]]) mx=1;
		if(q[mx][h[mx]]<q[2][h[2]]) mx=2;
		int x=q[mx][h[mx]++]+tag;
		if(i%T==0){
			if(!flag) flag=1;
			else putchar(' ');
			write(x);
		}
	}
	return 0;
}