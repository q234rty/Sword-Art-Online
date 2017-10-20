#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define pb push_back
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i<y;i++)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,in[N],ans,cnt;
vector <int> e[N];
map <int,int> f[N];
map <vector<int>,int> has;
bool hav[N<<2];	
inline int dfs(int x,int fa){
	if(f[x][fa]) return f[x][fa];
	vector<int> q;
	Rep(i,0,e[x].size()) if(e[x][i]!=fa) q.pb(dfs(e[x][i],x));
	sort(q.begin(),q.end());
	if(!has[q]) has[q]=++cnt;
	return f[x][fa]=has[q];
}
int main(){
	n=read();
	Rep(i,1,n){int x=read(),y=read();e[x].pb(y);e[y].pb(x);in[x]++;in[y]++;}
	For(i,1,n) if(in[i]<4) hav[dfs(i,0)]=1;
	For(i,1,cnt) if(hav[i]) ans++;
	cout<<ans<<endl;
	return 0;
}
