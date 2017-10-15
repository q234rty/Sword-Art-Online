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
struct que{
	int opt,l,r,x,id,bl;
	bool operator <(const que &a)const{
		return (bl==a.bl)?r<a.r:bl<a.bl;
	}
}q[N];
int n,m,a[N],block,ans[N],cnt[N],c=100000,b[N];
bitset <100005> f,h,g;
inline void add(int x){
	cnt[a[x]]++;
	if(cnt[a[x]]==1) f[a[x]]=1,g[b[x]]=1;
}
inline void del(int x){
	cnt[a[x]]--;
	if(cnt[a[x]]==0) f[a[x]]=0,g[b[x]]=0;
}
inline int query(int x){
	if(q[x].opt==3){
		int nm=q[x].x,flag=0;
		For(i,1,sqrt(nm)){
			if(flag) break;
			if(nm%i==0){
				if(cnt[i]&&cnt[nm/i]) flag=1;
			}
		}
		return flag;
	}
	if(q[x].opt==1){
		h=f;h>>=q[x].x;h&=f;
		if(!h.count()) return 0;
		else return 1;
	}
	if(q[x].opt==2){
		h=g;
		h>>=(c-q[x].x);
		h&=f;
		if(!h.count()) return 0;
		else return 1;
	}
}
int main(){
	n=read();m=read();
	For(i,1,n) a[i]=read(),b[i]=c-a[i];
	block=2*sqrt(m);
	For(i,1,m){
		q[i]=(que){read(),read(),read(),read(),i};
		q[i].bl=(q[i].l-1)/block+1;
	}
	sort(q+1,q+1+m);
	int L=q[1].l,R=q[1].r;
	For(i,L,R) add(i);
	ans[q[1].id]=query(1);
	For(i,2,m){
		while(L<q[i].l) del(L),L++;
		while(L>q[i].l) L--,add(L);
		while(R<q[i].r) R++,add(R);
		while(R>q[i].r) del(R),R--;
		ans[q[i].id]=query(i);
	}
	For(i,1,m){
		if(ans[i]==1) puts("yuno");
		else puts("yumi");
	}
	return 0;
}