#include<bits/stdc++.h>
#define ll long long
#define N 3005
#define For(i,x,id) for(int i=x;i<=id;i++)
#define Rep(i,x,id) for(int i=x;i>=id;i--)
#define mp make_pair
#define pa pair<int,int>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
struct data{int x,id;}a[3005];
bool operator <(data a,data b){return a.x>b.x;}
int n,m,b[N][N];
inline void doit(int x){
	sort(a+x,a+n+1);
	int sum=a[x].x;
	Rep(i,n,x+1){
		if(sum>1) sum-=2,b[a[x].id][a[i].id]=1,b[a[i].id][a[x].id]=-1;
		else if(sum==1) sum=0,a[i].x--,b[a[x].id][a[i].id]=b[a[i].id][a[x].id]=0;
		else if(sum==0) a[i].x-=2,b[a[x].id][a[i].id]=-1,b[a[i].id][a[x].id]=1;
	}
}
int main(){
	n=read();m=read();
	int x=0,sum=0;
	For(i,1,m){
		a[i]=(data){read(),i};
		x+=2*(n-i);
		sum+=a[i].x;
		if(sum>x){puts("no");return 0;}
	}
	For(i,m+1,n){
		a[i].id=i;
		x+=2*(n-i);
		a[i].x=min(a[i-1].x,x-sum);
		sum+=a[i].x;
	}
	if(sum!=x){puts("no");return 0;}
	For(i,1,n) doit(i);
	puts("yes");
	For(i,1,n){
		For(j,1,n){
			if(i==j) cout<<"X";
			else if(b[i][j]==-1) cout<<"L";
			else if(b[i][j]==1) cout<<"W";
			else cout<<"D";
		}
		cout<<endl;
	}
	return 0;
}