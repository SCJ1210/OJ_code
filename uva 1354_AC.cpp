//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define double long double
double R,ans;
int S;
struct P{
	double w,l,r;
};
void dfs(vector<P> v)
{
	if(v.size()==1)
	{
		double t=v[0].l+v[0].r;
		if(t<=R) ans=max(ans,t);
		return ;
	}
	for(int i=0;i<v.size();++i)
	{
		for(int j=0;j<v.size();++j)
		{
			if(i==j) continue;
			P x=v[i],y=v[j],z;
			z.w=x.w+y.w;
			double a,b;
			a=y.w/z.w;b=1-a;
			z.l=max(x.l+a,y.l-b);
			z.r=max(y.r+b,x.r-a);
			vector<P> tp;tp.push_back(z);
			for(int k=0;k<v.size();++k)
				if(k!=i&&k!=j) tp.push_back(v[k]);
			dfs(tp);
		}
	}
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	cout<<fixed<<setprecision(16);
	while(T--)
	{
		ans=-1;
		cin>>R>>S;
		vector<P> v;
		for(int i=0;i<S;++i)
		{
			int x;cin>>x;
			v.push_back({x,0,0});
		}
		dfs(v);
		if(ans==-1) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
}
