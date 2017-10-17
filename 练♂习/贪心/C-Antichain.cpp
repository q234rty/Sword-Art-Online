#include<bits/stdc++.h>
#define ll long long
#define N 2000005
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
char s[N];
int p,ans,n,flag;
int main(){
	scanf("%s",s);
	n=strlen(s);
	For(i,0,n-1){
		if(s[i]!=s[(i+1)%n]){
			if(s[i]!=s[(i+2)%n]) ans++;
			else if(s[i]!=s[(i+3)%n]) i++,ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}