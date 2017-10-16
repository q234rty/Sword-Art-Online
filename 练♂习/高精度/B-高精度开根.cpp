#include<bits/stdc++.h>
#define ll long long
#define int ll
#define mod 100000000
using namespace std;
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,len,st;
char s[1000005];
ll num[1000005],ans[1000005],nans[1000005],res[1000005];
ll mid[1000005],flag[1000005];
inline bool check(){
	int pos=1,pow=1;
	nans[1]=0;
	For(i,1,st){
		nans[pos]+=ans[i]*pow;pow*=10;
		if(i%8==0) pos++,pow=1,nans[pos]=0;
	}
	for(;!nans[pos];pos--);
	nans[0]=pos;
	For(i,1,res[0]) res[i]=0;
	res[0]=res[1]=1;
	For(i,1,n){
		For(j,1,mid[0]) mid[j]=0;
		mid[0]=0;
		For(j,1,nans[0]) For(k,1,res[0]) mid[j+k-1]+=nans[j]*res[k];
		mid[0]=nans[0]+res[0]-1;
		int j=1;
/*		for(;mid[j]||j<=mid[0];j++)
			if(mid[j]>=mod) mid[j+1]+=mid[j]/mod,mid[j]%=mod;
		mid[0]=j;*/
		For(j,1,mid[0]) mid[j+1]+=mid[j]/mod,mid[j]%=mod;
		if(mid[mid[0]+1]>0) mid[0]++;
		while(!mid[mid[0]]) mid[0]--;
		For(j,0,mid[0]) res[j]=mid[j];
	}
	For(i,1,flag[0]) flag[i]=0;
	flag[0]=0;
	For(i,1,res[0]) For(j,1,8) flag[++flag[0]]=res[i]%10,res[i]/=10;
	for(;!flag[flag[0]];flag[0]--);
	if(flag[0]>len) return 0;
	int i=len;
	for(;flag[i]==num[i]&&i;i--);
	if(flag[i]<=num[i]||!i) return 1;
	return 0;
}
signed main(){
	n=read();scanf("%s",s+1);
	len=strlen(s+1);
	For(i,1,len) num[len-i+1]=s[i]-48;
	if(n==1){
		For(i,1,len) cout<<s[i];
		return 0;
	}
	st=(len/n)+3;
	ans[0]=st;
	Rep(i,st,1){
		int l=0,r=9,Ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			ans[i]=mid;
			if(check()) Ans=mid,l=mid+1;
			else r=mid-1;
		}
		ans[i]=Ans;
	}
	for(;!ans[st]&&st>=0;st--);
	Rep(i,st,1) printf("%d",ans[i]);
	if(st<=0) printf("0");
	return 0;
}