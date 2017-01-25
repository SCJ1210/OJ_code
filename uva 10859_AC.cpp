//By SCJ
//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1000000000
struct P{
	int x,y;
	bool operator < (const P &rhs)const{
		if(x!=rhs.x) return x<rhs.x;
		return y<rhs.y;
	}
	P operator + (const P &rhs)const{
		return {x+rhs.x,y+rhs.y};
	}
}dp[1005][2];
vector<int> G[1005];
bool used[1005];
void dfs(int u,int pa)
{
	used[u]=1;
	if(G[u].size()==1&&pa!=-1)
	{
		dp[u][0]={0,0};
		dp[u][1]={1,0};
		return ;
	}
	dp[u][0]={0,G[u].size()};
	dp[u][1]={1,0};
	if(pa!=-1) dp[u][0].y-=1;
	for(int v:G[u])
	{
		if(used[v]) continue;
		dfs(v,u);
		dp[u][0]=dp[u][0]+dp[v][1];
		P tp=dp[v][0];tp.y+=1;
		dp[u][1]=dp[u][1]+min(tp,dp[v][1]);
	}
//	cout<<"  u="<<u<<endl;
//	cout<<dp[u][0].x<<' '<<dp[u][0].y<<endl;
//	cout<<dp[u][1].x<<' '<<dp[u][1].y<<endl;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		int n,m;cin>>n>>m;
		memset(used,0,sizeof(used));
		for(int i=0;i<=n;++i) G[i].clear();
		for(int i=0;i<m;++i)
		{
			int a,b;cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		P ans={0,0};
		for(int i=0;i<n;++i)
		{
			if(used[i]) continue;
			dfs(i,-1);
			ans=ans+min(dp[i][0],dp[i][1]);
		}
		cout<<ans.x<<' '<<m-ans.y<<' '<<ans.y<<endl;
	}
}
