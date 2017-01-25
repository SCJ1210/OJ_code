//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x2f2f2f2f
int n,m,d[15][15],dp[1<<15][15],nx[1<<15][15];
vector<int> w;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	memset(d,INF,sizeof(d));
	memset(dp,INF,sizeof(dp));
	cin>>n>>m;
	for(int i=0;i<n;++i) d[i][i]=0;
	for(int i=0;i<m;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=d[b][a]=c;
	}
	int k;cin>>k;
	for(int i=0;i<k;++i)
	{
		int x;cin>>x;
		w.push_back(x);
	}
	int F=(1<<n)-1;
	int A=F;
	int beg=F^(1<<w[0]);
	for(int i:w) A^=(1<<i);
	dp[beg][w[0]]=0;
	for(int S=F-1;S>=0;--S)
	{
		vector<int> O,Z;
		for(int i=0;i<n;++i)
			if(((S>>i)&1)==0) Z.push_back(i);
			else O.push_back(i);
		for(int g=0;g<Z.size();++g)
			for(int v:Z)
				for(int i:Z)
					if(dp[S][v]>dp[S][i]+d[i][v])
						dp[S][v]=dp[S][i]+d[i][v],nx[S][v]=i;
					else if(dp[S][v]==dp[S][i]+d[i][v]) nx[S][v]=min(nx[S][v],i);
		for(int v:Z)
			for(int i:O)
			{
				int r=S^(1<<i);
				if(dp[r][i]>dp[S][v]+d[v][i])
					dp[r][i]=dp[S][v]+d[v][i],nx[r][i]=v;
				else if(dp[r][i]==dp[S][v]+d[v][i]) nx[r][i]=min(nx[r][i],v);
			}
	}
	int ansMIN=INF,TA,TV;
	for(int S=F;S>=0;--S)
		if((S|A)==A) for(int v=0;v<n;++v)
			if(ansMIN>dp[S][v]) ansMIN=dp[S][v],TA=S,TV=v;
	stack<int> ans;ans.push(TV);
	while(1)
	{
		int r=(TA|(1<<TV));
		for(int i=0;i<n;++i)
		{
			if((r>>i)&1) continue;

			if(dp[TA][i]+d[i][TV]==dp[TA][TV])
			{
				ans.push(i);
				TV=i;
				break;
			}
			if(dp[r][i]+d[i][TV]==dp[TA][TV])
			{
				ans.push(i);
				TA=r;TV=i;
				break;
			}
		}
		if(TA==beg&&TV==w[0]) break;
	}
	cout<<"Minimum travel distance: "<<ansMIN<<endl;
	cout<<"Travel route:";
	while(ans.size()) cout<<' '<<ans.top(),ans.pop();
	cout<<endl;
}
