#include<bits/stdc++.h>
#define ll long long
#define mod 1000000000
using namespace std;
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
char ch1[10005],ch2[10005];
struct data{int a[1205],l;}a,b;
int la,lb,cnt;
inline void print(data a){
	while(a.a[a.l]==0) a.l--;
	Rep(i,a.l,1){
		if(i==a.l) printf("%d",a.a[i]);
		else printf("%09d",a.a[i]);
	}
}
inline data sub(data a,data b){
	int k;data c;
	For(i,1,1200){
		if(i<=b.l) c.a[i]=a.a[i]-b.a[i];
		else if(i<=a.l) c.a[i]=a.a[i];
		else c.a[i]=0;
		if(c.a[i]<0){
			c.a[i]+=mod;
			a.a[i+1]--;
		}
	}
	c.l=a.l;
	while(c.a[c.l]==0&&c.l) c.l--;
	return c;
}
inline void diva(){
	For(i,1,a.l){
		if(a.a[i]&1) a.a[i-1]+=mod/2;
		a.a[i]>>=1;
	}
	if(!a.a[a.l]) a.l--;
}
inline void divb(){
	For(i,1,b.l){
		if(b.a[i]&1) b.a[i-1]+=mod/2;
		b.a[i]>>=1;
	}
	if(!b.a[b.l]) b.l--;
}
inline bool bijiao(){
	if(a.l<b.l) return 0;
	if(a.l>b.l) return 1;
	Rep(i,a.l,1){
		if(a.a[i]>b.a[i]) return 1;
		else if(a.a[i]<b.a[i]) return 0;
	}
	return 1;
}
inline void mul(){
	Rep(i,a.l,1){
		a.a[i]<<=1;
		a.a[i+1]+=a.a[i]/mod;
		a.a[i]%=mod;
	}
	while(a.a[a.l]>0) a.l++;
	Rep(i,b.l,1){
		b.a[i]<<=1;
		b.a[i+1]+=b.a[i]/mod;
		b.a[i]%=mod;
	}
	while(b.a[b.l]>0) b.l++;
}
int main(){
	scanf("%s%s",ch1+1,ch2+1);
	la=strlen(ch1+1);lb=strlen(ch2+1);
	if(la%9) a.l=la/9+1;else a.l=la/9;
	if(lb%9) b.l=lb/9+1;else b.l=lb/9;
	For(i,1,a.l){
		int k1=max(1,la-i*9+1),k2=la-(i-1)*9;
		For(j,k1,k2) a.a[i]=a.a[i]*10+ch1[j]-48;
	}
	For(i,1,b.l){
		int k1=max(1,lb-i*9+1),k2=lb-(i-1)*9;
		For(j,k1,k2) b.a[i]=b.a[i]*10+ch2[j]-48;
	}
	while(1){
		if((a.a[1]%2==0)&&(b.a[1]%2==0)){diva();divb();cnt++;}
		else if(a.a[1]%2==0) diva();
		else if(b.a[1]%2==0) divb();
		if(bijiao()){
			a=sub(a,b);
			if(!a.l){
				while(cnt--) mul();
				print(b);break;
			}
		}
		else{
			b=sub(b,a);
			if(!b.l){
				while(cnt--) mul();
				print(a);break;
			}
		}
	}
	return 0;
}