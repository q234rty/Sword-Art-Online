#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define mp make_pair
#define pa pair<int,int>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int k,n,m,a[N],t[N];
pa h[N];
vector <pa> sum[N];
vector <pair<double,int> > ans;
int main(){
	k=read();n=read();m=read();
	For(i,1,k) a[i]=read();
//	For(i,1,k) h[i]=mp(0,0);
	For(i,1,n){
		int opt=read(),x=read(),y=read();
		t[i]=opt;
		if(opt==1) if(h[x].first<=y) h[x]=mp(y,i);
		if(opt==2) sum[x].push_back(mp(y,i));
		if(opt==3) ans.push_back(mp(y,i));
	}
	For(i,1,k){
		if(h[i].first>a[i]) sum[i].push_back(mp(h[i].first-a[i],h[i].second));
//		cout<<h[i].first<<" "<<a[i]<<endl;
//		cout<<sum[i].size()<<endl;
		sort(sum[i].rbegin(),sum[i].rend());
		ll s=a[i];
		for(int j=0;j<sum[i].size();j++){
			pa Q=sum[i][j];
			ans.push_back(mp(1.0*(s+Q.first)/s,Q.second));
			s+=Q.first;
		}
	}
	sort(ans.rbegin(),ans.rend());
	m=min((int)ans.size(),m);
	printf("%d\n",m);
	For(j,0,m-1) if(t[ans[j].second]==1) cout<<ans[j].second<<" ";
	For(j,0,m-1) if(t[ans[j].second]==2) cout<<ans[j].second<<" ";
	For(j,0,m-1) if(t[ans[j].second]==3) cout<<ans[j].second<<" ";
	return 0;
}
