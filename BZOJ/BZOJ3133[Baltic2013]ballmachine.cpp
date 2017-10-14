#include<bits/stdc++.h>
#define inf 1e9
#define N 100005
#define ll long long
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
}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) putchar('-'),x=-x;write(x);putchar('\n');}
int tot,root,n,m,size[N],p[N],rk[N],fa[N][18],dep[N],bin[18];
struct data{
	int x,val;
	inline bool operator <(const data &a)const{
		return val<a.val;
	}
};
vector <data> e[N];
bool vis[N];
inline void Dfs(int x){
	size[x]=1;
	For(i,1,17){
		if(dep[x]<bin[i]) break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i].x;
		fa[y][0]=x;dep[y]=dep[x]+1;
		Dfs(y);
		size[x]+=size[y];
		if(size[y]==1) e[x][i].val=e[x][i].x;
		else e[x][i].val=min(e[x][i].x,e[y][0].val);
	}
	sort(e[x].begin(),e[x].end());
}
inline void dfs(int x){
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i].x;
		dfs(y);
	}
	p[++tot]=x;
}
priority_queue <int,vector<int>,greater<int> > Q;
int main(){
	bin[0]=1;For(i,1,17) bin[i]=bin[i-1]<<1;
	n=read();m=read();
	For(i,1,n){
		int Fa=read();
		if(Fa) e[Fa].push_back((data){i,0});
		else root=i;
	}
	Dfs(root);dfs(root);
	For(i,1,n) rk[p[i]]=i;
	For(i,1,n) Q.push(i);
	while(m--){
		int opt=read(),num=read();
		if(opt==1){
			int x;
			For(i,1,num){
				x=p[Q.top()];
				vis[x]=1;
				Q.pop();
			}
			writeln(x);
		}else{
			int x=num,ans=0;
			Rep(i,17,0) if(vis[fa[x][i]]) x=fa[x][i],ans+=bin[i];
			vis[x]=0;Q.push(rk[x]);
			writeln(ans);
		}
	}
	return 0;
}