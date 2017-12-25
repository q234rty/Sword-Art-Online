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
char s[N],c[N];
int n,ch[N][26],end[N],sz,p[N];
inline void insert(){
	scanf("%s",c+1);
	int m=strlen(c+1),x=0;
	For(i,1,m){
		if(!ch[x][c[i]-'a']) ch[x][c[i]-'a']=++sz;
		x=ch[x][c[i]-'a'];
	}end[x]=m;
}
queue <int> Q;
int fail[N];
inline void lzq_AK(){
	Q.push(0);
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		For(i,0,25){
			if(!ch[x][i]) ch[x][i]=ch[fail[x]][i];
			else{
				if(x) fail[ch[x][i]]=ch[fail[x]][i];
				Q.push(ch[x][i]);
			}
		}
	}
}
int q[N],top;
int main(){
	scanf("%s",s+1);
	n=read();For(i,1,n) insert();
	lzq_AK();n=strlen(s+1);
	int x=0;q[top]=0;
	For(i,1,n){
		x=ch[x][s[i]-'a'];
		q[++top]=x;
		p[top]=i;
		if(end[x]) top-=end[x];
		x=q[top];
	}
	For(i,1,top) cout<<s[p[i]];
	return 0;
}
