//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 10005
int f[maxn],p[maxn];
pair<int,int> ans[maxn*2];
void sp(int aa,int bb)
{
	int d=(bb-aa+1)/2;
//	cout<<"  aa="<<aa<<"  bb="<<bb<<endl;
	for(int i=0;i<d;++i)
	{
		int a=aa+i,b=bb-d+i+1;
//		cout<<"  a="<<a<<"   b="<<b<<endl;
		int x=f[a],y=f[b];
		swap(f[a],f[b]);
		swap(p[x],p[y]);
	}
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
//	freopen("1611.in","r",stdin);
//	freopen("1611.out","w",stdout);
	int T;cin>>T;//cout<<T<<endl;
	while(T--)
	{
		int n,ct=0;cin>>n;//cout<<n<<endl;
		for(int i=1;i<=n;++i) cin>>f[i],p[f[i]]=i;//,cout<<f[i]<<' ';
		//cout<<endl;
		for(int r=1;r<=n;++r)
		{
			if(r==p[r]) continue;
			int d=p[r]-r+1;
			if(d%2){
				ans[ct++]={r+1,p[r]};
				sp(r+1,p[r]);
			}
			else{
				ans[ct++]={r,p[r]};
				sp(r,p[r]);
			}
			if(r==p[r]) continue;
			d=p[r]-r-1;int pos=p[r];
			ans[ct++]={r,p[r]+d};
			sp(r,p[r]+d);
		}
		cout<<ct<<endl;
		for(int i=0;i<ct;++i)
			cout<<ans[i].first<<' '<<ans[i].second<<endl;
//			cout<<min(ans[i].first,ans[i].second)
//			<<' '<<max(ans[i].first,ans[i].second)<<endl;
	}
}
