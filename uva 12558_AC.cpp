//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define INF 10000000000000000
int maxd;
vector<int> ans,tp;
unordered_set<int> st;
int get_first(int a,int b)
{
	int x;
	if(b%a==0) x=b/a;
	else x=b/a+1;
	return x;
}
void dfs(int dep,int aa,int bb,int la)
{
	//printf("maxd=%lld  dep=%lld   a=%lld   b=%lld   la=%lld\n",maxd,dep,aa,bb,la-1);
	if(dep==maxd)
	{
		//return ;
		if(aa==0){
			for(int i=maxd-1;i>=0;--i){
				if(tp[i]>ans[i]) break;
				else if(tp[i]<ans[i]){ans=tp;break;}
			}
		}
		return ;
	}
	int x=get_first(aa,bb);
	x=max(x,la);

	for(;;x++)
	{
		int a=aa,b=bb;
		if(bb*(maxd-dep+1)<=x*aa) break;
		//printf("maxd=%lld  dep=%lld   a=%lld   b=%lld   x=%lld  la=%lld\n",maxd,dep,aa,bb,x,la);
		while(st.find(x)!=st.end()) x++;
	if(dep==maxd-1)
	{
		if(aa!=1){
			return ;
		}
		else if(x==bb){
			tp[dep]=bb;
			dfs(dep+1,0,bb,bb);
			return ;
		}

	}
		a=a*x-b;
		b=b*x;
		int gd=__gcd(a,b);
		tp[dep]=x;
		dfs(dep+1,a/gd,b/gd,x+1);
	}
}
main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	for(int i=0;i<100;++i) ans.push_back(INF),tp.push_back(INF);
	for(int ca=1;ca<=T;++ca)
	{
		for(int i=0;i<100;++i) ans[i]=tp[i]=INF;
		int aa,bb,k;cin>>aa>>bb>>k;
		cout<<"Case "<<ca<<": "<<aa<<"/"<<bb<<"=";
		st.clear();
		for(int i=0;i<k;++i){
			int x;cin>>x;
			st.insert(x);
		}
		for(maxd=1;;++maxd)
		{
			dfs(0,aa,bb,get_first(aa,bb));
			//cout<<maxd<<endl;
			if(ans[maxd-1]!=INF)
			{
				for(int i=0;i<maxd;++i)
				{
					if(i!=0) cout<<"+";
					cout<<1<<"/"<<ans[i];
				}
				cout<<endl;
				break;
			}
		}
	}
}
