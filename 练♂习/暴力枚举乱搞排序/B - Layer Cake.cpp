#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<time.h>
#include<iostream>
#define inf 1e9
#define mod 998244353
#define N 4005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int n,t[1000005],ans1,ans2;
struct data{int x,y;}a[N];
inline bool operator <(data a,data b){return a.x<b.x;}
inline void add(int x){
	for(;x;x-=(x&-x)) t[x]++;
}
inline int query(int x){
	int sum=0;
	for(;x<=1000000;x+=(x&-x)) sum+=t[x];
	return sum;
}
ll ans;
int main(){
	n=read();
	For(i,1,n) a[i]=(data){read(),read()};
	For(i,1,n) if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
	sort(a+1,a+1+n);
	Rep(i,n,1){
		add(a[i].y);
		For(j,1,n){
			if(ans<1ll*query(a[j].y)*a[i].x*a[j].y){
				ans1=a[i].x;ans2=a[j].y;
				ans=1ll*query(a[j].y)*a[i].x*a[j].y;
			}
		}
	}
	writeln(ans);
	printf("%d %d",ans1,ans2);
	return 0;
}