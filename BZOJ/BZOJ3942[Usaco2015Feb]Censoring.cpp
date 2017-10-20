#include<bits/stdc++.h>
#define ll long long
#define N 1000005
#define oo 1e9
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
char s[N],c[N];
int n,m,nxt[N],top,q[N],p[N];
int main(){
	scanf("%s%s",s+1,c+1);
	n=strlen(s+1);m=strlen(c+1);
	int j=0;
	For(i,2,m){
		while(j&&c[i]!=c[j+1]) j=nxt[j];
		if(c[i]==c[j+1]) j++;nxt[i]=j;
	}
	j=0;
	For(i,1,n){
		while(j&&s[i]!=c[j+1]) j=nxt[j];
		if(s[i]==c[j+1]) j++;
		p[++top]=j;q[top]=i;
		if(j==m) top-=m,j=p[top];
	}
	For(i,1,top) printf("%c",s[q[i]]);
	return 0;
}