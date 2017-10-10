#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<set>
#include<map>
#include<queue>
#include<vector>
#define inf 1e9
#define mod 10007
#define N 1005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int m,n,line[8][N][N],num[8][N];
struct data{int x,y;}a[8],b[N];
int ans,s[N],l;
inline bool isline(data a,data b,data c){
	if(a.x==b.x&&b.x==c.x){
		if((a.y<b.y&&b.y<c.y)||(a.y>b.y&&b.y>c.y)) return 1;
		else return 0;
	}
	if(a.y==b.y&&b.y==c.y){
		if((a.x<b.x&&b.x<c.x)||(a.x>b.x&&b.x>c.x)) return 1;
		else return 0;
	}
	if(a.x<b.x&&b.x<c.x||(a.x>b.x&&b.x>c.x)){
		if((a.y<b.y&&b.y<c.y)||(a.y>b.y&&b.y>c.y)){
			if(1.0*(b.y-a.y)/(b.x-a.x)==1.0*(c.y-b.y)/(c.x-b.x)) return 1;
		}
		else return 0;
	}
	return 0;
}
bool tvis[8],vis[N];
inline void clean(int l,int &r){For(i,l,r) vis[s[i]]=0;r=l-1;}
inline int dfs(){
	if(l>s[0]) return 1;
	int t=s[l],ll=s[0];
	For(i,1,m)
		if((!tvis[i])&&num[i][t]>=0){
			tvis[i]=1;
			bool flag=1;
			For(j,1,num[i][t])
				if(!vis[line[i][t][j]]){
					if(s[0]+1>m){flag=0;break;}
					else s[++s[0]]=line[i][t][j],vis[line[i][t][j]]=1;
				}
			if(!flag){clean(ll+1,s[0]);tvis[i]=0;continue;}
			++l;flag=dfs();--l;
			clean(ll+1,s[0]);tvis[i]=0;
			if(flag) return 1;
		}
	return 0;
}
int main(){
	m=read();n=read();
	For(i,1,m) a[i]=(data){read(),read()};
	For(i,1,n) b[i]=(data){read(),read()};
	For(i,1,m) For(j,1,n) For(k,1,n){
		if(isline(a[i],b[k],b[j])) line[i][j][++num[i][j]]=k;
		if(num[i][j]>m-1){num[i][j]=-1;break;}
	}
//	For(i,1,m) For(j,1,n) cout<<num[i][j]<<endl;
	For(i,1,n){
		vis[s[s[0]=l=1]=i]=1;
		ans+=dfs();
		vis[i]=0;
	}
	writeln(ans);
	return 0;
}