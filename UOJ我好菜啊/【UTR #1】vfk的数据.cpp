#include<bits/stdc++.h>
#define inf 1e9
#define N 500005
#define M 1000005
#define mod 1000000007
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int n;
pair <int,string> s[10005];
int main(){
	n=read();
	For(i,1,n) cin>>s[i].second,s[i].first=s[i].second.size();
	sort(s+1,s+1+n);
	For(i,1,n) cout<<s[i].second<<endl;
	return 0;
}